#include<iostream>
#include<map>
#include<cstdlib>
#include<time.h>
#include<algorithm>
using namespace std;

#define MAX 100000


int a[MAX];
bool inseries[100010];
int ansarr[100000];


int main()
{
	srand(time(NULL));
	
	for(int i=0;i<100010;i++)
		inseries[i]=false;
	
	int m;
	cin>>m;
	
	for(int i=0;i<m;i++)
		cin>>a[i];
	
	sort(a,a+m);
	if(m>2)
	{
	inseries[a[1]]=true;
	inseries[a[2]]=true;
	
	ansarr[0]=a[1];
	ansarr[1]=a[2];
	}
	else
	{
	inseries[a[0]]=true;
	inseries[a[1]]=true;
	
	ansarr[0]=a[0];
	ansarr[1]=a[1];
	}	
	int k=2;
	
	
	for(int i=2;i<m;i++)
	{
		bool flag=true;
		for(int j=0;j<k;j++)
		{
			if((a[i]+ansarr[j])%2==0)
			{
			if(inseries[(a[i]+ansarr[j])/2])
			{	
				flag=false;break;
			}}
		}
		if(flag)
		{
			inseries[a[i]]=true;
			ansarr[k++]=a[i];
		}
		
	}
	sort(ansarr,ansarr+k);
	cout<<k<<endl;
	
	for(int i=0;i<k;i++)
		cout<<ansarr[i]<<" ";
	

}




