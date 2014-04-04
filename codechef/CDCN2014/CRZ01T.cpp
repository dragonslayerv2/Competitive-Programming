#include<iostream>
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


double nroot(int k,int n)
{
	double last=2; 
	double nw=2;
	do
	{
		last=nw;
		nw=((k-p(last,n))/(n*p(last,n-1)))+last;
	}
	while(!(nw<=last+PRECISION&&nw>=last-PRECISION));
	return nw;
}
int main()
{
	for(int n=1;n<=1000;n++)
		for(int k=1;k<=1000;k++)
		{
			cout.setf(ios::fixed);
			cout.precision(6);
			
			if(n==0)
				cout<<0.0<<endl;
			else
			{
				if(n==8&&k==128)
					continue;
				double value=k;
				value*=p(n,n);
				cout.setf(ios::fixed);
				cout.precision(6);
				cout<<n<<" "<<k<<" ";
				cout<<nroot(value,n)<<endl;
				
			}
			
		}
		
	
}
