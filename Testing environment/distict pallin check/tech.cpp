#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
	string testfile;
	cin>>testfile;
	testfile+=" >test.txt";
	int cycles;
	cin>>cycles;
	ofstream log("log.txt");
	while(cycles--)
	{
		
		
		system(testfile.c_str());
		
		string program1="p1.exe <test.txt >o1.txt";
		string program2="p2.exe <test.txt >o2.txt";
		system(program1.c_str());
		system(program2.c_str());
		
		
		ifstream o1("o1.txt");
		ifstream o2("o2.txt");
		
		int ans1;
		o1>>ans1;
		int ans2;
		o2>>ans2;
		if(ans1!=ans2)
		{
			
			cout<<"*";
			string a;
			ifstream test("test.txt");
			test>>a;
			log<<a;
			log<<ans1<<" "<<ans2<<endl;
		
		}
		else
		{
			cout<<".";
		}
		
	}
	cout<<"OVER";
}
