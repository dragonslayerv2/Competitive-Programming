#include<iostream>
#include<set>
#include<vector>
#include<list>
#include<map>
using namespace std;

struct person
{
	list<int> parent;
	list<int> child;
	list<int> brothers;
};

int main()
{
	freopen("test.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int n,r;
	cin>>n>>r;
	map<string,int> id;
	int currentID=0;

	vector<person> P(n);

	for(int i=0;i<r;i++)
	{
		//first person
		string name1;
		cin>>name1;
		
		int id1;
		if(id.find(name1)==id.end())
		{
			id[name1]=currentID;
			currentID++;	
		}
		id1=id[name1];
		
		string is;
		cin>>is;
		
		//relation
		string relation;
		cin>>relation;
		string of;
		cin>>of;	
		//-- second person
		string name2;
		cin>>name2;
		
		int id2;
		if(id.find(name2)==id.end())
		{
			id[name2]=currentID;
			currentID++;	
		}
		id2=id[name2];
		
		
		
		 switch(relation[0])
		{
			case 'f': 	parentList[id2].push_back(id1); childList[id1].push_back(id2); break;
			case 'm': 	parentList[id2].push_back(id1); childList[id1].push_back(id2); break;
			case 'd':	childList[id2].push_back(id1); childList[id1].push_back(id1); break;
			case 's':	if(relation[1]=='o')
						{
							childList[id2].push_back(id1); childList[id1].push_back(id1);
						}
						else
						{
							brotherList[id2].push_back(id1);brotherList[id1].push_back(id2);
						}
						break;
			case 'b':	brotherList[id2].push_back(id1);brotherList[id1].push_back(id2); break;
		}
	}
	
	vector<vector<int> > G(n,vector<int>(n,10000));
	

	
	// all pair shortest path problem
	
	vector<vector<vector<int> > > dist(n+1,vector<vector<int> >(n+1,vector<int>(n+1)));
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dist[0][i][j]=G[i-1][j-1];
	
	vector<vector<int> > P(n,vector<int>(n));
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(dist[k-1][i][j]>dist[k-1][i][k]+dist[k-1][k][j] )
				{
					dist[k][i][j]=dist[k-1][i][k]+dist[k-1][k][j];
					P[i][j]=k;
				}
				else
					dist[k][i][j]=dist[k-1][i][j];
			}
	int q;
	cin>>q;
	
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		cout<<dist.back()[id[a]+1][id[b]+1]<<endl;
	}
	
}
