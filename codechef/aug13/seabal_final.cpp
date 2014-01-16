#include<iostream>
#include<cstdio>
#include<vector>
#include<deque>
#include<list>
using namespace std;

#define MAX 100005





int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<int> array(n+1);
	
	for(int i=1;i<=n;i++)
		cin>>array[i];
	
	vector<int> front(100005),back(100005);	
	for(int i=1;i<=m;i++)
	{
		front[i]=i+1;
		back[i]=i-1;
	}
	
	vector<pair<int,int> > range(m+1);
	
	
	vector<vector<int> > baloons(MAX);
	for(int i=1;i<=m;i++)
	{
		cin>>range[i].first>>range[i].second;
		baloons[range[i].first].push_back(i);
		baloons[range[i].second].push_back(i);
	}
	
	int k;
	cin>>k;
	
	
	int ans=0;
	int count=0;
	
	for(int i=0;i<k;i++)
	{
		int pos;
		cin>>pos;
		pos=ans+pos;
		
		array[pos]--;
		if(!array[pos])
		{
			for(auto j=baloons[pos].begin();j!=baloons[pos].end();j++)
			{
				if(range[*j].first!=0&&range[*j].second!=0)
				{ 
					if(range[*j].first==range[*j].second)
					{
						count++;
						range[*j].first=range[*j].second=0;
					}
					else
					{
						if(range[*j].first==pos)
						{
							if(front[pos]>range[*j].second)
							{
								count++;
								range[*j].second=0;
							}	
							else	
							{
								range[*j].first=front[pos];
								baloons[front[pos]].push_back((*j));
							}
						}
						
						if(range[*j].second==pos)
						{
	
							if(back[pos]<range[*j].first)
							{
								count++;
								range[*j].first=0;
							}
							else
							{
								range[*j].second=back[pos];
								baloons[back[pos]].push_back((*j));
							}
						}
					}
				}
			}
			front[back[pos]]=front[pos];
			back[front[pos]]=back[pos];
		}
		ans=count;
		cout<<ans<<endl;
	}
}


