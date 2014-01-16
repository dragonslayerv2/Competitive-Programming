#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;



int main()
{
	srand(time(NULL));
	const int size=100;
	char a[size];
	a[size-1]='\0';
	for(int i=0;i<size-1;i++)
	{
		a[i]='a'+(rand()%26);
	}
	cout<<a<<endl;	
}
