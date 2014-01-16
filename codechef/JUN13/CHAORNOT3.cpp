#include<iostream>
#include<map>
#include<cstdlib>
#include<time.h>
#include<algorithm>
using namespace std;


#define MAX 100000


int a[MAX];
int ansarr[100000];

bool inseries[100010];


int main()
{
	srand(time(NULL));
	for(int i=0;i<100010;i++)
	{
		inseries[i]=false;
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}		
	for(int i=0;i<m;i++)
    {
            swap(a[i],a[rand()%(i+1)]);// Do care for this i+1
    }
   // for(int i=0;i<m;i++)
    //	cout<<a[i]<<" ";
	int count=m;
	if(m>50000)
		count=50000;
		
	int n=count;
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		
		inseries[a[i]]=true;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(inseries[a[i]]&&inseries[a[j]])
			{
				if(a[j]*2-a[i]<100010)
					inseries[a[j]*2-a[i]]=false;
				
			//	cout<<"deleting "<<a[j]*2-a[i]<<endl;
			}
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
