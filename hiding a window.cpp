
#include<windows.h>
using namespace std;

int main()
{
	HWND window;
	AllocConsole();
	window=FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(window,0);	
}
