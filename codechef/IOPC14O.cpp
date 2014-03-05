#include<iostream>
using namespace std;

inline long long gcd( long long a, long long b)
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

int count1(long long a)
{
	int count=0;
	while(a&&(a&1))
	{
		a>>=1;
		count++;
	}
	if(a)
		return -1;
	else
		return count;
}

int count2(long long a)
{
	int count=0;
	while(a&&!(a&1))
	{
		a>>=1;
		count++;
	}
	if(a==1)
		return count;
	else
		return -1;
}

pair<int,int> count3(long long a)
{
	int count1=0,count2=0;
	while(a&&!(a&1))
	{
		a>>=1;
		count1++;
	}
	while(a&&(a&1))
	{
		a>>=1;
		count2++;
	}
	if(!a)
		return make_pair(count1,count2);
	else
		return make_pair(-1,-1);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long p,q;
		cin>>p>>q;
		long long GCD=gcd(p,q);
		p/=GCD;
		q/=GCD;
		int i,j;
		if(p==1)
		{
			pair<int,int> count=count3(q);
			if(count.first==-1)
				i=-1;
			else
			{
				j=count.second;
				i=count.first+j;	
			}
		}
		else
		{
			
			j=count1(q);
			if(j==-1)
				i=-1;
			i=j-count2(p);
			if(i>j)
				i=-1;
			
		}
		//cout<<i<<" "<<j<<endl;
		if(i>=0&&j>0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
