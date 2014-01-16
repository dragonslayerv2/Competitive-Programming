#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

int main()
{
	char a[1000];
	char b[1000];
	ifstream f1("out1.txt"),f2("out2.txt");
	
	int i=1;
	while(a&&b)
	{
		
		f1>>a;
		f2>>b;
		if(strcmp(a,b)!=0)
		{	cout<<"Line No"<<i;
			cout<<a<<endl;
			cout<<b<<endl;
			
			cin.get();
		}
		
		i++;
		
	}
	
}
