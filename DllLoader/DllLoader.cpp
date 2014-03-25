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
	HINSTANCE hGetProcIDDLL = LoadLibrary("Nirvana_ext.dll");
	pause();
	return 0;
}