/*
	Name: Range Maximum Sum Query 
	Copyright: 
	Author: Shobhit Saxena
	Date: 08/01/14 20:57
	Description: This algorithm uses kadanes and DP to solve the problem in O(n^2) preprocessing and O(1) query time.
				The idea is to fill row by row
*/

#include<iostream>
#include<limits>
#include<vector>
using namespace std;



int main()
{
	vector<long long> a;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long x;
		cin>>x;
		a.push_back(x);
	}
	
	vector<vector<long long> > solution(n,vector<long long>(n));
	for(int x=0;x<n;x++)
	{
		bool flag=true;
    	long long max_so_far=numeric_limits<long long>::min(), max_ending_here=0;
    	for(int y=x;y<n;y++)
    	{
            if(a[y]>0&&flag) {flag=false;max_so_far=0;}
            if(flag)
            {            
            	if(a[y]>max_so_far)                             
                	max_so_far=a[y];
            }
            else
            {
            	max_ending_here+=a[y];
            	if(max_ending_here<0)
               		max_ending_here=0;
            	if(max_ending_here>max_so_far)
                	max_so_far=max_ending_here;   
            }
            solution[x][y]=max_so_far;
    	}
	}
	
	int q;
	cin>>q;
	for(int i=0;i<q;i++) // 0 indexed
	{
		int x,y;
		cin>>x>>y;
		cout<<solution[x][y]<<endl;
	}
}
