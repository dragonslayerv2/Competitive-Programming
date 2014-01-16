/*
	Name: Longest Common Substring
	Copyright: 
	Author: Shobhit Saxea
	Date: 10/12/13 18:23
	Description: This code finds the longest common substring among two string
				 Linear Memory with O(n^2) time.
*/


#include<iostream>
#include<limits>
#include<vector>
using namespace std;

pair<int,pair<int,int> > longestCommonSubstring(const string &a, const string &b)
{
	vector<vector<int> > dparray(a.size(),vector<int>(b.size()));
	
	int MAX=numeric_limits<int>::min();
	int posi=-1;
	int posj=-1;
	
	for(int j=0;j<b.size();j++)
	{
		dparray[0][j]= (a[0]==b[j]);
		if(MAX<dparray[0][j])
		{
			posi=0;posj=j;
			MAX=dparray[0][j];
		}
	}
	
	
	for(int i=1;i<a.size();i++)
	{	
		dparray[i][0]=(a[i]==b[0]);
		
		if(MAX<dparray[i][0])
		{
			posi=i;posj=0;
			MAX=dparray[i][0];
		}
		
		for(int j=1;j<b.size();j++)
		{
			if(a[i]==b[j])
				dparray[i][j]=1+dparray[i-1][j-1];
			else
				dparray[i][j]=0;
				
			if(MAX<dparray[i][j])
			{
				posi=i;posj=j;
				MAX=dparray[i][j];
			}
		}
	}
	return make_pair(MAX,make_pair(posi-MAX+1,posj-MAX+1));
}

int main()
{
	string a="Shobhit Saxena";
	string b="Saxena";
	
	pair<int,pair<int,int> > solution=longestCommonSubstring(a,b);
	
	for(int i=0;i<solution.first;i++)
		cout<<a[i+solution.second.first];
	cout<<endl;
	
	for(int i=0;i<solution.first;i++)
		cout<<b[i+solution.second.second];
}
