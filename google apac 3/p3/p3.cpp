#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<limits>
using namespace std;
typedef vector<list<pair<long long,long long> > > graph;

struct cmp
{
	bool operator()(pair<long long,long long> a,pair<long long,long long> b)
	{
		return a>b;
	}
};
vector<long long> dijkstras(const graph &G,long long source)
{
	const long long INVALID = numeric_limits<long long>::max();
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >, cmp > Q;
	
	vector<bool> used(G.size(),false);  
	vector<long long> distances(G.size(),INVALID);  
	
	distances[source]=0;
	Q.push(make_pair(0,source));
	
	while(!Q.empty())
	{
		pair<long long,long long> current=Q.top();
		Q.pop();
		if(!used[current.second])
		{
			used[current.second]=true;
			for(list<pair<long long,long long> >::const_iterator i=G[current.second].begin();i!=G[current.second].end();i++)
			{
				if(distances[i->first]>distances[current.second]+i->second)
				{
					distances[i->first]=distances[current.second]+i->second;
					Q.push(make_pair(distances[i->first],i->first));
				}
					
			}
		}
	}
	return distances;	
}

int main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	long long T;
	cin>>T;
	for(long long t=0;t<T;t++){
		cout<<"Case #"<<t+1<<": "<<endl;
		long long metros;
		cin>>metros;
		vector<vector<long long> > stationDistances(metros);
		vector<long long> stationCount(metros);
		vector<long long> waiting(metros);
		
		
		for(long long i=0;i<metros;i++){
			cin>>stationCount[i]>>waiting[i];
			for(long long j=0;j<stationCount[i]-1;j++){
				long long x;
				cin>>x;
				stationDistances[i].push_back(x);
			}
		}
		
		long long tunnels;
		cin>>tunnels;
		vector<pair<long long,long long> > tunnelStarting(tunnels);
		vector<pair<long long,long long> > tunnelEnding(tunnels);
		vector<long long> tunnelTime(tunnels);
		for(long long i=0;i<tunnels;i++){
			cin>>tunnelStarting[i].first>>tunnelStarting[i].second>>tunnelEnding[i].first>>tunnelEnding[i].second;
			tunnelStarting[i].first--;
			tunnelStarting[i].second--;
			tunnelEnding[i].first--;
			tunnelEnding[i].second--;
			cin>>tunnelTime[i];
		}
		
		vector<vector<long long> > stationRank(metros);
		vector<vector<long long> > tunnelRank(metros);
		
		long long rank=0;
		for(long long i=0;i<stationRank.size();i++){
			stationRank[i].resize(stationCount[i]);
			tunnelRank[i].resize(stationCount[i]);
			for(long long j=0;j<stationRank[i].size();j++){
				stationRank[i][j]=rank++;
				tunnelRank[i][j]=rank++;
			}
		}
		
		vector<list<pair<long long,long long> > > graph(rank);
		
		for(long long i=0;i<stationRank.size();i++){
			for(long long j=0;j<stationRank[i].size();j++){
				long long tunnel=tunnelRank[i][j];
				long long station=stationRank[i][j];
				graph[station].push_back(make_pair(tunnel,0));
				graph[tunnel].push_back(make_pair(station,waiting[i]));
			}
			
			for(long long j=0;j<stationRank[i].size()-1;j++){
				long long presentStation=stationRank[i][j];
				long long nextStation=stationRank[i][j+1];
				graph[presentStation].push_back(make_pair(nextStation,stationDistances[i][j]));
				graph[nextStation].push_back(make_pair(presentStation,stationDistances[i][j]));
			}
		}
		
		for(long long i=0;i<tunnels;i++){
			long long startingStation=tunnelRank[tunnelStarting[i].first][tunnelStarting[i].second];
			long long endStation=tunnelRank[tunnelEnding[i].first][tunnelEnding[i].second];
			graph[startingStation].push_back(make_pair(endStation,tunnelTime[i]));
			graph[endStation].push_back(make_pair(startingStation,tunnelTime[i]));
		}
		/*
		for(int i=0;i<graph.size();i++){
			cout<<i<<"--> ";
			for(list<pair<long long, long long> >::iterator j=graph[i].begin();j!=graph[i].end();j++)
				cout<<"( "<<j->first<<" "<<j->second<<" ) --> ";
			cout<<endl;
		}*/
		long long q;
		cin>>q;
		while(q--){
			long long startMetro, startStation,endMetro,endStation;
			cin>>startMetro>>startStation>>endMetro>>endStation;
			startMetro--;startStation--;endMetro--;endStation--;
			vector<long long> distances=dijkstras(graph,tunnelRank[startMetro][startStation]);
			long long ans=min(distances[stationRank[endMetro][endStation]],distances[tunnelRank[endMetro][endStation]]);
			if(ans==numeric_limits<long long>::max())
				cout<<-1<<endl;
			else
				cout<<ans<<endl;
		}
	}
}
