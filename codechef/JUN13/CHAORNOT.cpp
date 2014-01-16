#include<iostream>
#include<map>
#include<cstdlib>
#include<algorithm>
using namespace std;


#define MAX 100000


int a[MAX];
int ansarr[6000];

int main()
{
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}		
	
	int count=m;
	if(m>1000)
		count=1000;
		
	int n=count;

	map<double,bool> inseries;
	for(int i=0;i<n;i++)
	{
		inseries[a[i]]=true;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			inseries[double((a[i]+a[j]))/2]=false;
		}
	}
	count=0;
	for(int i=0;i<n;i++)
	{
		if(inseries[a[i]])
		{		
			ansarr[count]=a[i];
			count++;
		}	
	}
	cout<<count<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<ansarr[i]<<" ";
	}
	
	
}
