#include<iostream>
using namespace std;

long long f(int n)
{
	long long fact=1;
	for(int i=1;i<=n;i++)
		fact*=n;
	return fact;
}

long long g(int a,int n)
{
	long long p=1;
	for(int i=0;i<n;i++)
		p*=a;
	return p;
}
int main()
{
	for(int a=1;a<=100;a++)
	{
		cout<<a<<" =>";
		for(int k=1;k<20;k++)
			cout<<(f(k)>g(a,k));
		cout<<endl;
	}
}
