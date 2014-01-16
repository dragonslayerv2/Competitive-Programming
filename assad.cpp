#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void computePiFunction(string &p,long long *Pi)
{
		long long m=p.size();

		Pi[0]=-1;
		long long k=-1;
		
		for(long long i=1;i<m;i++)
		{
		
			while(k>=0&&p[k+1]!=p[i])
				{k=Pi[k];}
			if(p[k+1]==p[i])
				k++;
			Pi[i]=k;	
		}
}
long long matcher(string &P,string &T,long long *Pi)
{
		long long count=0;
		long long m=P.size();
		long long q=-1;
		for(long long i=0;T[i];i++)
		{
			
			while(q>=0&&P[q+1]!=T[i])
			{
				q=Pi[q];
			}
			if(P[q+1]==T[i])	q++;
			if(q==m-1)
			{
				count++;
				q=Pi[q];
			}
			//cout<<"At "<<T[i]<<" = "<<q<<endl;	
			
		}
		return count;
}
#define PATTERN_SIZE 10000000
long long Pi[PATTERN_SIZE];
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		string a;
		string b;
		cin>>a;
		cin>>b;
		long long l;
		cin>>l;
		long long hasha[26]={0};
		long long hashb[26]={0};
		
		for(long long i=0;i<a.size();i++)
		{
			hasha[a[i]-'a']++;
		}
		for(long long i=0;i<b.size();i++)
		{
			hashb[b[i]-'a']++;
		}
		long long count=0;
		for(long long i=0;i<26;i++)
		{
			count+=hasha[i]*hashb[i];
		}
		cout<<count;
		
		for(long long i	=2;i<=l;i++)
		{
			long long count=0;
			
			for(long long j=0;j<a.size()-i+1;j++)
			{
				string pattern=a.substr(j,j+i);
				computePiFunction(pattern,Pi);			
				count+=matcher(pattern,b,Pi);
			}
			cout<<" "<<count;
		}
		cout<<endl;
	}
}
