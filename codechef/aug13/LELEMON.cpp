#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		vector<int> roomno;
		roomno.reserve(m);
		for(int i=0;i<m;i++)
		{
			int r;
			cin>>r;
			roomno.push_back(r);
		}
		
		vector<vector<int> > room(n);
		for(int i=0;i<n;i++)
		{
			int ci;
			cin>>ci;
			room.reserve(ci);
			for(int j=0;j<ci;j++)
			{
				int v;
				cin>>v;
				room[i].push_back(v);
			}
			sort(room[i].begin(),room[i].end());
		}
		
		long long ans=0;
		
		for(int i=0;i<roomno.size();i++)
		{
			if(room[roomno[i]].size())
			{
				ans+=room[roomno[i]].back();	
				room[roomno[i]].pop_back();
			}
		}
		cout<<ans<<endl;
	}
}
