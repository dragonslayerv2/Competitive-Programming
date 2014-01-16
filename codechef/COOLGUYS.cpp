#include<iostream>
#include<cmath>
using namespace std;
inline int GCF(long long a, long long b)
{
   long long temp;    
   while(b)
   {
           temp=a;
           a=b;
           b=temp%b;
   }
   return a;
}

long long getcount(long long n)
{
	int sqrtn=sqrt(n);
	long long ans=0;
	for(int i=1;i<=sqrt(n);i++)
	{
		ans+=n/i;
	}
	ans=ans*2;
	ans-=sqrtn*sqrtn;
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long count=getcount(n);
		long long nsqr=n*n;
		long long gcf=GCF(count,nsqr);
		cout<<count/gcf<<"/"<<(n*n)/gcf<<endl;
	}
}
