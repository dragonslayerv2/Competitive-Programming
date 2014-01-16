#include<iostream>
using namespace std;

double sol(double p, int x,int y)
{
	return (2*(1-p)*x-y)*p+(2*p*y-x)*(1-p);
}
int main()
{
	cout.precision(6);
	cout.setf(ios::fixed);
	int t;
	cin>>t;
	while(t--)
	{
		double p;
		cin>>p;
		double MAX=max(sol(p,10000,0),sol(p,0,10000));
		MAX=max(MAX,0.0);
		//MAX=max(MAX,sol(p,0,1));
		//MAX=max(MAX,sol(p,1,0));
		cout<<10000+MAX<<endl;
		
	
	}
	return 0;
}
