#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;


long long getTime(pair<long long,long long> team,pair<long long,long long> checkpoint,long long speed){
	long long x=team.first-checkpoint.first;
	long long y=team.second-checkpoint.second;
	return ceil(((double)x*x+y*y)/(speed*speed));
}

int main(){
//	freopen("test.txt","r",stdin);
	long long n,m,k;
	cin>>n>>m>>k;
	vector<pair<long long,long long> > teams(n);
	for(long long i=0;i<n;i++)
		cin>>teams[i].first>>teams[i].second;
	
	vector<pair<long long,long long> > checkpoints(m);
	for(int i=0;i<m;i++)
		cin>>checkpoints[i].first>>checkpoints[i].second;
	
	vector<long long> speed(n);
	for(int i=0;i<n;i++)
		cin>>speed[i];
	
	vector<pair<long long,pair<int,int> > > times;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			times.push_back(make_pair(getTime(teams[i],checkpoints[j],speed[i]),make_pair(i,j)));
	
	sort(times.begin(),times.end());
	
	vector<bool> isTeamUsed(n);
	vector<bool> isCheckPointUsed(m);
	
	long long time=0;
	int taken=0;
	for(int i=0;i<times.size()&&taken<k;i++){
		if(!isTeamUsed[times[i].second.first]&&!isCheckPointUsed[times[i].second.second]){
			isTeamUsed[times[i].second.first]=isCheckPointUsed[times[i].second.second]=true;
			time=max(time,times[i].first);
			taken++;
		}
	}
	cout<<time;
}
