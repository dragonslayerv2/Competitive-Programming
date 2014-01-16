#include<iostream>
#include<algorithm>
#include<array>

using namespace std;

int main()
{
	int a[5];
	for(int i=0;i<5;i++)
	{
		cin>>a[i];
	}
	
	sort(a,a+5);
	for(int i=0;i<5;i++)
	{
		cout<<a[i];
	}
}
