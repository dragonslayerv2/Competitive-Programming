#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
//	freopen("test.txt","r",stdin);
	int n;
	long long s,e;
	cin>>n>>s>>e;
	vector<pair<long long,long long> > area(n);
	for(int i=0;i<n;i++)
	{
		long long x,p;
		cin>>x>>p;
		area[i]=make_pair(x-p,x+p);
	}
	sort(area.begin(),area.end());
	

	stack<pair<long long,long long> > S;
	S.push(area[0]);
	for(int i=1;i<n;i++){
		if(area[i].first<=S.top().second+1){
			pair<long long,long long> a=S.top();
			S.pop();
			S.push(make_pair(min(a.first,area[i].first),max(a.second,area[i].second)));
		}
		else
			S.push(area[i]);
	}
	
	area.clear();
	while(!S.empty()){
		area.push_back(S.top());
		S.pop();	
	}
	
	for(int i=0;i<area.size();i++){
		if(area[i].first<s)
			area[i].first=s;
		if(area[i].second>e)
			area[i].second=e;
		
		if(area[i].first>area[i].second)
			area[i]=make_pair(-1,-1);
	}
	long long uncovered=e-s;
	for(int i=0;i<area.size();i++)
	{
		if(area[i].first<0)
			continue;
		else
			uncovered-=area[i].second-area[i].first;
	}
		
	cout<<uncovered;
}
