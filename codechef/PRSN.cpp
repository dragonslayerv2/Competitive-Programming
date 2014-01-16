#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

vector<vector<bool> > lookuptablefirst;
vector<vector<int > > lookuptablesecond; 

long long solve(vector<int> &released,int l,int h)
{
	if(l>h)
		return 0;
	if(l<1)
		return 0;
	if(lookuptablefirst[l][h]==false)
	{
		long long min_bribe=numeric_limits<long long>::max();
		bool isReleased=false;
		for(int i=0;i<released.size();i++)
		{
		
			if(released[i]>=l)
			{
				if(released[i]<=h)
				{
					isReleased=true;
					long long current_bribe=solve(released,l,released[i]-1)+solve(released,released[i]+1,h);
						current_bribe+=((released[i]-1)-l)+1;
					current_bribe+=(h-(released[i]+1))+1;
					min_bribe=min(min_bribe,current_bribe);
				}	
			}
		}
		lookuptablefirst[l][h]=true;
		if(isReleased)
			lookuptablesecond[l][h]=min_bribe;
		else
			lookuptablesecond[l][h]=0;	
	}
	return lookuptablesecond[l][h];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		lookuptablefirst.clear();
		lookuptablesecond.clear();
		int m,z;
		
		cin>>m>>z;
		lookuptablefirst.resize(m+2,vector<bool> (m+2));
		lookuptablesecond.resize(m+2,vector<int> (m+2));
		vector<int> released;
		while(z--)
		{
			int n;
			cin>>n;
			released.push_back(n);
		}
		cout<<solve(released,1,m)<<endl;	
	}
}
