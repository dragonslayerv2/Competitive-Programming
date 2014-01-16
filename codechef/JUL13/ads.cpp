#include<iostream>
#include<array>
using namespace std;


int main()
{
	array<int,5> a;
	a[0]=1;
	a[0]=2;
	a[0]=3;
	a[0]=4;
	a[0]=5;
	
	for(int &x:a)
	{
		cout<<x;
	}
}
