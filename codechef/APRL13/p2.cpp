#include<iostream>
#include<algorithm>
using namespace std;


int partition(int a[],int l,int h)
{
	int pivot=a[h];
	
	int i=l;
	int j=h-1;
	while(i<j)
	{
		while(a[i]<=pivot&&i<j)
			i++;
		while(a[j]>pivot&&i<j)
			j--;
		swap(a[i],a[j]);
	}
	swap(a[i+1],a[h]);
	return j;
}

int kthelement(int a[],int n,int k)
{
	int l=0;
	int h=n-1;
	int r=-1;
	while(r!=k)
	{
		int r=partition(a,l,h);
		if(k==r)
			return a[k];
		else if(r<k)
		{
			l=r+1;
		}
		else
			h=r-1;
		
	}
}


int main()
{
	int a[]={4,5,3,2,2,6};
	cout<<partition(a,0,4);
	cout<<"---";
	for(int i=0;i<sizeof(a)/4;i++)
	{
		cout<<" "<<a[i];
	}

}
