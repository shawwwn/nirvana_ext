#include "IAT.h"

IATHookInstaller::IATHookInstaller(const std::string& nativeRootModule, const std::string& moduleName, const std::string& functionName, void* newFuncAddress) :
    m_moduleName(moduleName),
    m_functionName(functionName)
{
    ReplacePtr(nativeRootModule, m_moduleName, m_functionName, newFuncAddress, m_OldFunction, m_funcPtrLocation);
    assert(m_OldFunction != 0);
}

IATHookInstaller::~IATHookInstaller()
{
    try
    {
        assert(m_OldFunction == 0);
        if (m_OldFunction != 0)
        {
            CleanUp();
        }
    }
    catch(...)
    {
    }
}

void IATHookInstaller::CleanUp()
{
    if (m_OldFunction != 0)
    {
        assert(m_funcPtrLocation != NULL);

        if (m_funcPtrLocation != NULL)
        {
            DWORD oldrights;
            DWORD newrights = PAGE_READWRITE;

            VirtualProtect(m_funcPtrLocation, sizeof(LPVOID), newrights, &oldrights);
            *m_funcPtrLocation = m_OldFunction;
            VirtualProtect(m_funcPtrLocation, sizeof(LPVOID), oldrights, &newrights);
            
            m_OldFunction = 0;
        }
    }
}

void IATHookInstaller::ReplacePtr(const std::string& nativeRootModule,
                                  const std::string& moduleName,
                                  const std::string& functionName,
                                  void* newFuncAddress, 
                                  void*& oldFuncAddress, 
                                  void**& FuncAddressLocation)
{
    HMODULE hModule = GetModuleHandleA(nativeRootModule.size() == 0 ? NULL : nativeRootModule.c_str());
    if (hModule == NULL)
    {
        throw std::exception("GetModuleHandleA for nativeRootModule returned NULL");
    }
    HMODULE hResModule = NULL;
    
    IMAGE_IMPORT_DESCRIPTOR* iid = NULL;
    std::vector<std::string> duplicateCheck;

    if (FindPEChildImage(hModule, moduleName, hResModule, iid, duplicateCheck) == false)
    {
        throw std::exception("module not found");
    }
    
    int ptrVal = (int)iid;

    void** funcPtr = FindFunctionAddressInPEImage(iid, functionName, hResModule);
    if (funcPtr == NULL)
    {
        throw std::exception("function not found");
    }
    
    if (funcPtr != newFuncAddress)
    {
        DWORD oldrights;
        DWORD newrights = PAGE_READWRITE;

        VirtualProtect(funcPtr, sizeof(LPVOID), newrights, &oldrights);
        oldFuncAddress = *funcPtr;
        FuncAddressLocation = funcPtr;
        *funcPtr = newFuncAddress;
        VirtualProtect(funcPtr, sizeof(LPVOID), oldrights, &newrights);
    }
}

// Originally from http://stackoverflow.com/questions/769537/hook-loadlibrary-call-from-managed-code
// What's been added in this code is that we perform the search recursive because the original routine for some reasons only searched for
// immediate dependencies. The app depends32 displays a hierarchy, after looking at that it should be obvious what I am saying here.
// duplicateCheck is necessary because in the hierarchy 1 dll might appear multiple times, so this vector is there
// to avoid infinite loops.
// Also split that function into 2 for better readibility.
bool IATHookInstaller::FindPEChildImage(HMODULE hRootModule, 
                                        const std::string& moduleName, 
                                        HMODULE& hResModule, 
                                        IMAGE_IMPORT_DESCRIPTOR*& pIID, 
                                        std::vector<std::string>& duplicateCheck)
{
    //parse dos header
    IMAGE_DOS_HEADER* dos_header = (IMAGE_DOS_HEADER*)hRootModule;
    if (dos_header->e_magic != IMAGE_DOS_SIGNATURE) 
        throw std::exception("not a dos program");

    //parse nt header
    IMAGE_NT_HEADERS* nt_header = (IMAGE_NT_HEADERS*)(dos_header->e_lfanew + (SIZE_T)hRootModule);
    if (nt_header->Signature != IMAGE_NT_SIGNATURE)
        throw std::exception("not a windows program");

    //optional header (pretty much not optional)
    IMAGE_OPTIONAL_HEADER optional_header = nt_header->OptionalHeader;
    if (optional_header.Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC)
        return false;

    IMAGE_IMPORT_DESCRIPTOR* idt_address = (IMAGE_IMPORT_DESCRIPTOR*)(optional_header.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress + (SIZE_T)hRootModule);
    if (!optional_header.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size)
        return false;

    for(IMAGE_IMPORT_DESCRIPTOR* iid = idt_address; iid->Name != NULL; iid++)
    {
        char* iidname = (char*)(iid->Name + (SIZE_T)hRootModule);
        //check the import filename
        if (!_stricmp(moduleName.c_str(), iidname))
        {
            hResModule = hRootModule;
            pIID = iid;
            return true;
        }
        else
        {
            if (std::find(duplicateCheck.begin(), duplicateCheck.end(), iidname) == duplicateCheck.end())
            {
                duplicateCheck.push_back(iidname);

                HMODULE childModule = GetModuleHandleA(iidname);
                if (childModule && FindPEChildImage(childModule, moduleName, hResModule, pIID, duplicateCheck))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void** IATHookInstaller::FindFunctionAddressInPEImage(IMAGE_IMPORT_DESCRIPTOR* iid, const std::string& funcName, HMODULE hRootModule)
{
    //enumerate imported functions for this dll
    for (int funcIdx = 0; *(funcIdx + (LPVOID*)(iid->FirstThunk + (SIZE_T)hRootModule)) != NULL; funcIdx++)
    {
        //check if the function matches the function we are looking for
        char* modFuncName = (char*)(*(funcIdx + (SIZE_T*)(iid->OriginalFirstThunk + (SIZE_T)hRootModule)) + (SIZE_T)hRootModule + 2);
        if (!_stricmp(funcName.c_str(), modFuncName)) 
        {
            return funcIdx + (LPVOID*)(iid->FirstThunk + (SIZE_T)hRootModule);
            
        }
    }
    return NULL;
}