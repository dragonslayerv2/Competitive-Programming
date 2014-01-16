#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	freopen("test.txt","w",stdout);
	cout<<46<<endl;
	for(int i=0;i<46;i++)
	{
		cout<<rand()%10<<" ";
	}
	cout<<endl;
}
