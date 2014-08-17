#include<iostream>
#include<map>
#include<vector>
using namespace std;


vector<pair<long long,long long> > colours;

map<pair<int,int> ,pair<long long,long long> > DP;
#define pow2(i)  ((long long)(1)<<i)
pair<long long,long long> solve(int i,int k)
{
	//cout<<"AT "<<i<<" "<<k;
	if(DP.find(make_pair(i,k))==DP.end())
	{
		if(i==colours.size())
		{
			if(k==0)
				DP[make_pair(i,k)]=make_pair(0,1);
			else
				DP[make_pair(i,k)]=make_pair(0,0);
		}
		else
		{
			if(k==0)
			{
				pair<long long,long long> solution=solve(i+1,0);
				
				solution.first*=pow2(colours[i].second);
				solution.first+=colours[i].first*(pow2(colours[i].second-1))*solution.second;
				solution.second*=pow2(colours[i].second);
				DP[make_pair(i,k)]=solution;
			}
			else
			{
				pair<long long,long long> solution1=solve(i+1,k);
				pair<long long,long long> solution2=solve(i+1,k-1);
				
				solution2.first*=pow2(colours[i].second)-1;
				solution2.first+=colours[i].first*pow2(colours[i].second-1)*solution2.second;
				solution2.second*=pow2(colours[i].second)-1;	
				
				if(!solution1.second&&!solution2.second)
					DP[make_pair(i,k)]= make_pair(0,0);
				else if(!solution2.second)
					DP[make_pair(i,k)]= solution1;
				else if(!solution1.second)
					DP[make_pair(i,k)]= solution2;
				else
					DP[make_pair(i,k)]= make_pair(solution1.first+solution2.first,solution1.second+solution2.second);
			}
		}		
	}
	return DP[make_pair(i,k)];
}
int main()
{
	//freopen("sample.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		colours.assign(40,pair<long long,long long>());
		
		for(int i=0;i<n;i++)
		{
			long long a,b;
			cin>>a>>b;
			a--;
			colours[a].second++;
			colours[a].first+=b;
		}
		DP.clear();
		pair<long long,long long> solution=solve(0,m);
		cout.setf(ios::fixed);
		cout.precision(6);
	//	cout<<solution.first<<" "<<solution.second<<endl;
		if(solution.second==0)
			cout<<0.0<<endl;
		else
			cout<<((double)solution.first)/solution.second<<endl;
	}
}
