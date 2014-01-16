#include<iostream>
#include<map>
#include<climits>
#include<vector>
using namespace std;

map<int,map<int,pair<int,int> > > hashvalue;
map<int,map<int,bool> > exists;
pair<int,int> solve(int i,int j,vector<int> &colours)
{
	if(!exists[i][j])
	{
		pair<int,int> results;
		if(i==j)
			results=make_pair(colours[i],0);
		else
		{
			pair<int,int> result=make_pair(INT_MAX,INT_MAX);
			
			for(int k=i;k<j;k++)
			{
				pair<int,int> a=solve(i,k,colours);
					pair<int,int> b=solve(k+1,j,colours);
				
				int concentration=(a.first+b.first)%100;
					int gas=a.second+b.second+a.first*b.first;
				
				if(gas<result.second)
					result=make_pair(concentration,gas);
			}
			results=result;
		}
		exists[i][j]=true;
		hashvalue[i][j]=results;
	}
	return hashvalue[i][j];
}

int main()
{
	int n;
	while(cin>>n)
	{
		hashvalue.clear();
		exists.clear();
		vector<int> colours(n);
		for(int i=0;i<n;i++)
			cin>>colours[i];
		cout<<solve(0,n-1,colours).second<<endl;	
	}
}
