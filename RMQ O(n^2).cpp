/*
	Name: Range Minimum Query O(n^2) algorithm.
	Copyright: 
	Author: Shobhit Saxena
	Date: 12/03/13 00:38
	Description: Stores RMQ for every possible combination of i and j. Dynamic programming reduces the complexity from O(n^3) to O(n^2).
*/

#include<iostream>
#include<vector>
using namespace std;


void preprocess(vector<int> arr,vector<vector<int> > &RMQ,int n)
{
	for(int i=0;i<n;i++)
		RMQ[i][i]=i;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[RMQ[i][j-1]])
				RMQ[i][j]=j;
			else
				RMQ[i][j]=RMQ[i][j-1];
		}
	}
}


int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	vector<vector<int> > RMQ(n,vector<int>(n));
	preprocess(arr,RMQ,n);
	while(1)
	{
		int i,j;
		cin>>i>>j;
		cout<<arr[RMQ[i][j]]<<endl;
	}

}
