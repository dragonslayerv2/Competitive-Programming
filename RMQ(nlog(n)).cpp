/*
	Name: Range Minimum Query( Nlog(n) algorithm)
	Copyright: 
	Author: Shobhit Saxena
	Date: 12/03/13 21:33
	Description: This is an O(Nlog(N)) algorithm. Preprocessing Time O(nlogn) and query time O(log(gap)) and space req=O(nlog(n))
*/



#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*//----------------------------------debug--------------------------------------
void print(vector<vector<int> > arr,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=log(n)+2;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
}
*/
//------------------------------------------------------------------------------

void preprocess(vector<int> &arr,vector<vector<int> > &RMQ,int n)
{
	for(int i=0;i<n;i++)
		RMQ[i][0]=arr[i];
	
	for(int j=1,p=2;p<=n;j++,p*=2)
	{
		for(int i=0;i+p<=n;i++)
			RMQ[i][j]=min(RMQ[i][j-1],RMQ[i+p/2][j-1]);
	}
	//	print(RMQ,n);

}


int query(int i,int j,vector<vector<int> > &RMQ)
{
	int gap=j-i+1;
	int p=-1;
	int po=1;
	//cout<<"gap="<<gap;
	while(gap) // calculates 2^(floor(logk)) and floor(logk)
	{
		gap=gap>>1;
		p++;
		po<<=1;
	}
	po>>=1;
	
	//cout<<" "<<"p="<<p<<endl;
	return min(RMQ[i][p],RMQ[j-po+1][p]);
}
int main()
{
	
	
	int n;
	cin>>n;
	vector<int> arr(n);
	vector<vector<int> > RMQ(n,vector<int>(1+ceil(log(n))));
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	
	preprocess(arr,RMQ,n);
	
	while(1)
	{
		int a,b;
		cin>>a>>b;
		cout<<query(a,b,RMQ)<<endl;
	}
	return 0;
}
