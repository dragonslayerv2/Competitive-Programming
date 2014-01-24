#include<vector>
#include<queue>
#include<iostream>
using namespace std;


int main()
{
	int n,s,t;
	cin>>n>>s>>t;
	s--;
	t--;
	vector<int> next(n);
	for(int i=0;i<n;i++)
	{
		cin>>next[i];
		next[i]--;
	}
	vector<int> distance(n,-1);
	distance[s]=0;
	queue<int> Q;
	Q.push(s);
	while(!Q.empty())
	{
		int current=Q.front();
		Q.pop();
		if(distance[next[current]]==-1)
		{
			distance[next[current]]=distance[current]+1;
			Q.push(next[current]);
		}
	}

	cout<<distance[t];
}
