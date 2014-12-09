#include<iostream>
#include<vector>
#define MAX 1000000000
using namespace std;
//----------------------------------------

int bin(vector<int>V,int x)
{
	int high=V.size();
	int low=0;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(V[mid]>x)
			high=mid-1;
		else if(V[mid]<x)
			low=mid+1;
		else
			return V[mid];
	}
	return V[mid];
}
int main()
{
	int n;
	cin>>n;
	int flag=0;
	string str;
	int x,y;
	vector<int> V;
	//V.push_back(1);
	int a=1;
	for(;a<=MAX;)
	{
		V.push_back(a);
		a*=2;
	}
	int count;
	while(n--)
	{
		cin>>str;
		if(str[1]=='i')
			flag=!flag;
		else if(str[1]=='b')
		{
			count=0;
			int count1=0;
			cin>>x>>y;
			int z=bin(V,x);
			//cout<<z;
			if(z!=x)
				z/=2;
			while(z>2)
			{
				z=z/4;
			}
			//cout<<z;
			if(z==1 && flag==0)
				count++;
			else if(z==2 && flag==1)
				count++;
			while(x!=y)
			{
				//cout<<"k";
				if(x<y)
					y/=2;
				else if(x>y)
					x/=2;
				count1++;
			}
			if(count==0)
			count1++;
			count=count+count1/2;
			
			cout<<count<<endl;
		}
		
		else if(str[1]=='r')
		{
			count=0;
			int count1=0;
			cin>>x>>y;
			int z=bin(V,x);
			if(z!=x)
				z/=2;
			while(z>2)
			{
				z=z/4;
			}
			if(z==2 && flag==0)
				count++;
			else if(z==1 && flag==1)
				count++;
			while(x!=y)
			{
				if(x<y)
					y/=2;
				else if(y<x)
					x/=2;
				count1++;
			}
			if(count==0)
			count1++;
			count=count+count1/2;
			cout<<count<<endl;
		}
	}
}
