/*
	Name: Check whether there exist a subset of elements such that there XOR = a given number. Given the Goal number is very small.
	Copyright: 
	Author: Shobhit Saxena
	Date: 24/01/14 18:15
	Description: This problem can be solved using DP. 
					Use DP on n and G. This will give you the answer
				
				Number with hamming distance = the given number can also be solved using this.
*/


#include<iostream>
#include<map>
#include<vector>
using namespace std;

#define DEBUG

map<int,map<int,bool> > solution;
map<int,map<int,bool> > exist;

bool solve(vector<int> &array,int n,int G,int k=0)
{
	if(!exist[n][k])
	{
		bool ans;
		if(n<0)
			ans=(k==G);
		else
			ans=solve(array,n-1,G,k^array[n])||solve(array,n-1,G,k);
		solution[n][k]=ans;
		exist[n][k]=true;
	}
	return solution[n][k];	
}
int main()
{
	#ifdef DEBUG
		freopen("test.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i=0;i<n;i++)
		cin>>array[i];
	int goal;
	cin>>goal;
	cout<<solve(array,n-1,goal);
}
