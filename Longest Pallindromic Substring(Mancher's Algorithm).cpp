/*
	Name: Longest Pallindromic Substring(Manchers Algorithm)
	Copyright: 
	Author: Shobhit Saxena
	Date: 10/12/13 20:18
	Description: This is a O(n) algorithm to solve Longest Pallindromic Substring Problem.
				Space O(n).
				refer to  http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;



vector<int> LPS(const string &a,char HASHCHAR='#')
{
	//---------------------- generating hashed string---------------------------
	vector<char> hashedstring(2*a.size()+1);
	int k=0;
	hashedstring[k]=HASHCHAR;
	k++;
	for(int i=0;i<a.size();i++)
	{
		hashedstring[k++]=a[i];
		hashedstring[k++]=HASHCHAR;
	}
	//--------------------------------------------------------------------------
	vector<int> P(hashedstring.size(),0);
	
	int C=0;
	int R=0;
	long long count=0;
	for(int i=1;i<hashedstring.size();i++)
	{
		int i_mirror=C*2-i;
		P[i] = (R > i) ? min (R-i, P[i_mirror]):0;
		
		int current_expan=0;
		 while (hashedstring[i+1+P[i]]==hashedstring[i-1-P[i]])      
		 {
		 	
		 	P[i]++;
		 	current_expan++;
		 }
		 count+=current_expan/2;
		
		if (i + P[i] > R) 
		{
			
			C = i;      
			R = i+P[i];    
		}
	}
	cout<<count<<endl;
	return P;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a;	
		cin>>a;
		LPS(a);
	}
	
}
