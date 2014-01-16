#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define MAX 100010
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
	sort(a,a+m);
	
	count--;
	a[1]=-1;
	m--;
	int dif=a[2]-a[0];
	
	for(int i=3;i<m;i++)
	{
		if(a[i]-a[i-1]==dif)
		{
			a[i]=-1;
			count--;
		}
	}

	int j=0;
	for(int i=0;i<m;i++)
	{
		if(a[i]!=-1)
			a[j++]=a[i];
	}
	
	if(count>1000)
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
