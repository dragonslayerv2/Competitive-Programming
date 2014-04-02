#include<iostream>
#include<map>
#include<climits>
#include<list>
#include<vector>
using namespace std;

map<int,map<int,pair<int,int> > > cost;
map<int,map<int,bool> > exist;


#define INVALID 1600000000
pair<int,int> solve(vector<vector<int> > &Cost,vector<vector<int> > &Time,int source,int time)
{
	if(!exist[source][time])
	{
		exist[source][time]=true;
		cost[source][time]=make_pair(INVALID,INVALID);
		pair<int,int> solution=make_pair(INVALID,INVALID);
		if(time<0)
			solution=make_pair(INVALID,INVALID);
		else if(source==Cost.size()-1)
			solution=make_pair(0,0);
		else
		{	
			for(int i=0;i<Cost.size();i++)
			{
				if(i!=source)
				{
					pair<int,int> move=solve(Cost,Time,i,time-Time[source][i]);
					if(move.first!=INVALID)
					{
						move=make_pair(move.first+Cost[source][i],Time[source][i]+move.second);
						solution=min(solution,move);
					}
				}
			}
		}
		exist[source][time]=true;
		cost[source][time]=solution;
		//cout<<"Returning "<<solution.first<<" "<<solution.second<<endl;
	}
	return cost[source][time];
}


int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		int n,t;
		cin>>n>>t;
	
		vector<vector<int> > cost(n,vector<int>(n)),time(n,vector<int>(n));
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>time[i][j];
				
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>cost[i][j];
				
		pair<int,int> solution;
		solution=solve(cost,time,0,t); 
		if(solution.first>=INVALID)
			cout<<-1;
		else
			cout<<solution.first<<" "<<solution.second;
		cout<<endl;
	}
}
