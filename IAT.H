#pragma once

#include <assert.h>
#include <vector>
#include <string>
#include <Windows.h>
#include <algorithm>    // std::find

class IATHookInstaller
{
public:
    // If a function pointer is retrieved by the dynamic method, the dll and the function pointer are not
    // part of the exe's IAT. (most probably this is also true for delay loaded dlls).
    // But the native dll itself might have dependencies in its IAT, and if this is true, IAT hooking
    // can play with those pointers.
    // E.g. managed project loads any native dlls via loadlibrary (I mean the PInvoke calls are done dynamically).
    // It means that the managed exe's IAT will most probably _not_ contain the dll in which the hook is supposed to happen.
    // (My experience is that a managed binary's IAT only contains mscoree.dll and one function from that.)
    // But once a native dll is loaded, we can go to the native dll's IAT.
    // This is why the nativeRootModule is needed here. If we know that dll1 is loaded dynamically, but dll1
    // links with dll2, we can hook the function calls from dll1 to dll2 by replacing the function pointers in
    // dll1's IAT. In this case we specify dll1 as nativeRootModule, dll2 as moduleName, the name of the
    // function as functionName and our hook function's address in the last parameter.
    // If the hooking was successful, to call the original function you can get its pointer via GetOldFunctionPtr().
    IATHookInstaller(const std::string& nativeRootModule, const std::string& moduleName, const std::string& functionName, void* newFuncAddress);
    ~IATHookInstaller();

    // You need to call CleanUp manually. This is so because from a desctructor I cannot throw
    // any exception that contains all the details of the problem. Also, this class is not
    // logger aware. So to make sure that the caller gets the details of any errors he is
    // forced to call cleanup and then handle all exceptions. The destructor asserts if
    // cleanup has not been called.
    void CleanUp();

    void* GetOldFunctionPtr()
    {
        return m_OldFunction;
    };

private:
    static void ReplacePtr(const std::string& nativeRootModule,
                           const std::string& moduleName,
                           const std::string& functionName,
                           void* newFuncAddress, 
                           void*& oldFuncAddress, 
                           void**& FuncAddressLocation);

    static bool FindPEChildImage(HMODULE hRootModule, const std::string& moduleName, HMODULE& hResModule, IMAGE_IMPORT_DESCRIPTOR*& pIID, std::vector<std::string>& duplicateCheck);
    static void** FindFunctionAddressInPEImage(IMAGE_IMPORT_DESCRIPTOR* iid, const std::string& funcName, HMODULE hRootModule);

    void* m_OldFunction;
    void** m_funcPtrLocation;
    std::string m_moduleName;
    std::string m_functionName;
};