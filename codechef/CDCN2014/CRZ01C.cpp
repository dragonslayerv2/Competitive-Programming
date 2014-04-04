#include<iostream>
#include<cmath>
using namespace std;

#define PRECISION 0.0000001
double p(double n,int m)
{
    if(m==0) return 1;
    
    double x=p(n,m/2);
    if(m%2==0) 
               return (x*x);
    else
               return ((x*x)*n);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout.setf(ios::fixed);
		cout.precision(6);
		
		if(n==0)
			cout<<0.0<<endl;
		else
		{
			cout.setf(ios::fixed);
			cout.precision(6);
			cout<<exp(log(k*p(n,n))/n)<<endl;
		}
	}
}
