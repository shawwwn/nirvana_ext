#include <windows.h>
#include <iostream>
using namespace std;

// pause the prompt
void pause()
{
	cin.ignore();
	cin.get();
}

int main() {
	cout << "Load Library..." << endl;
	HINSTANCE hGetProcIDDLL = LoadLibrary("Nir_Plugin_CursorBind.dll");
	pause();
	return 0;
}