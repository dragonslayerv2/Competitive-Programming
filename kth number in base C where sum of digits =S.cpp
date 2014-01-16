/*
	Name: Kth number in base C where sum of digits = S
	Copyright: 
	Author: Shobhit Saxena
	Date: 11/08/13 18:41
	Description: 
*/

#include<iostream>
#include<vector>
using namespace std;


long long pow(int n,int m)
{
    if(m==0) return 1;
    
    long long x=pow(n,m/2);
    if(m%2==0) 
               return x*x;
    else
               return x*x*n;
}


vector<vector<pair<bool,long long> > > lookuptable(100,vector<pair<bool,long long> >(100));


long long F(int n,int s,int C)
{
	if(n<=0) // this is a very imp point.... this is same as 0C0 is 1
	{
		if(s==0)
			return 1;
		else
			return 0;
	}
	if(n==1)
	{
		if(s<C)
			return 1;
		else
			return 0;
	}
	
	else
	{
		if(!lookuptable[n][s].first)
		{	
			long long count=0;
			for(int i=0;i<C;i++)
				count+=F(n-1,s-i,C);
			lookuptable[n][s].first=true;
			lookuptable[n][s].second=count;
		}
			
		return lookuptable[n][s].second;
	}	
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		lookuptable.clear();
		lookuptable.assign(100,vector<pair<bool,long long> >(100));
		int s,k,C;
		cin>>s>>k>>C;
		
		int n=0;
		while(F(n,s,C)<k)
			n++;
	
		long long ans=0;
		
		for(int i=n;i>=1;i--)
		{
			int thisdigit=0;
			int count=0;
			while(count+F(i-1,s-thisdigit,C)<k)
			{
				count+=F(i-1,s-thisdigit,C);
				thisdigit++;
			}	
			k-=count;
			ans+=thisdigit*pow(C,i-1);
			s-=thisdigit;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
