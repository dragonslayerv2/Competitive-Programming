#include<iostream>
#include<limits>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;

struct cmp
{
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		return a>b;
	}
};

vector<int> bucket;

vector<int> dijkstras(int source)
{
	const int INVALID = INT_MAX;
	priority_queue<pair<int,int>,vector<pair<int,int> >, cmp > Q;
	
	vector<bool> used(bucket[0],false);  
	vector<int> distances(bucket[0],INVALID);  
	
	distances[source]=0;
	Q.push(make_pair(0,source));
	
	while(!Q.empty())
	{
		
		pair<int,int> current=Q.top();
	//	cout<<current.first<<endl;
		Q.pop();
		if(!used[current.second])
		{
			used[current.second]=true;
			if(distances[current.second]>1000000000){
				distances[current.second]=INT_MAX;
			}else{
				for(int i=1;i<bucket.size();i++)
				{
					int dest=(current.second+bucket[i])%bucket[0];
					if(INT_MAX-distances[current.second]<bucket[i]){
						continue;
					}
					if(distances[dest]>distances[current.second]+bucket[i])
					{
						distances[dest]=distances[current.second]+bucket[i];
						Q.push(make_pair(distances[dest],dest));
					}
						
				}
			}
		}
	}
	return distances;	
}

int main(){
//	freopen("test.txt","r",stdin);
	int b,q;
	cin>>b>>q;
	bucket.resize(b);
	for(int i=0;i<b;i++)
		cin>>bucket[i];

	vector<int> distances=dijkstras(0);
	
	while(q--){
		int x;
		cin>>x;
		cout<<((distances[x%bucket[0]]<=x)?"yes":"no")<<endl;
	}
}
