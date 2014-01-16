#include<iostream>
#include<vector>
using namespace std;
int count=0;
bool iscorrect(vector<int> a,int k)
{
	
	vector<bool> hash(k+1);
	
	for(int i=1;i<a.size();i++)
		hash[a[i]]=true;
	
	for(int i=1;i<=k;i++)
		if(!hash[i])
			return false;
	
	cout<<"GOt";
	for(int i=1;i<a.size();i++)
		cout<<a[i];
	cout<<endl;
	return true;
	
}

void brute(int n,int k,vector<int> &a,int i=1)
{
	if(i==n+1)
	{
		if(iscorrect(a,k))
			count++;
		return;
	}
	for(int j=1;j<=k;j++)
	{
		a[i]=j;
		brute(n,k,a,i+1);
	}
}


int main()
{
	vector<int> a(6+1);
			count=0;
			brute(6,2,a);
			cout<<count<<"\t";	
/*	for(int n=1;n<10;n++)
	{
		for(int k=1;k<10;k++)
		{
			vector<int> a(n+1);
			count=0;
			brute(n,k,a);
			cout<<count<<"\t";	
		}
		cout<<endl;
	}*/
}
