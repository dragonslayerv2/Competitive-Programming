#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
	string testfile;
	cin>>testfile;
	int cycles;
	cin>>cycles;
	while(cycles--)
	{
		testfile+=" >test.txt";
		system(testfile.c_str());
		
		string program1="p1.exe <test.txt >o1.txt";
		string program2="p2.exe <test.txt >o2.txt";
		system(program1.c_str());
		system(program2.c_str());
		
		
		fstream o1("o1.txt");
		fstream o2("o2.txt");
		
		int ans1;
		o1>>ans1;
		int ans2;
		o2>>ans2;
		if(ans1!=ans2)
		{
			cout<<"Failed";
			break;
		}
	}
	cout<<"OVER";
}
