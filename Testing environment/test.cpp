#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;

int main()
{
	ofstream out("test.txt");
	
	srand(time(NULL));
	int t=10;
	out<<t<<endl;
	while(t--)
	{
		int n=rand()%10;
		out<<n<<endl;
		for(int i=0;i<n;i++)
		{
			out<<rand()%10;
			out<<" ";
		}
		out<<endl;
	}
}
