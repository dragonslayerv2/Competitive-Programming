#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


pair<int,int> getmaxvalue(const map<int,pair<int,list<int> > > &MAP)
{
	int MAX=INT_MIN;
	int maxpos=-1;
	for(auto i=MAP.begin();i!=MAP.end();i++)
	{
		MAX=max(MAX,(i->second).first);
		maxpos=i->first;
	}
	return make_pair(MAX,maxpos);
}

void erase_element(map<int,pair<int,list<int> > > &MAP,int element)
{
	for(auto i=MAP.begin();i!=MAP.end();i++)
	{
		for(auto j=(i->second).second.begin();j!=(i->second).second.begin();j++)
		{
			
			if((*j)==element)
			{
				*j=-1;				
				(i->second).first--;
			}
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		map<int,pair<int,list<int> > > row;
		map<int,pair<int,list<int> > > column;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			row[x].first++;
			row[x].second.push_back(y);
			
			column[y].first++;
			column[y].second.push_back(x);			
		}
		
		int count=0;
		while(n>0)
		{
			pair<int,int> maxrow=getmaxvalue(row);
			pair<int,int> maxcolumn=getmaxvalue(column);
			if(maxrow.first>maxcolumn.first)
			{
				n-=row[maxrow.second].first;
				row.erase(maxrow.second);	
				erase_element(column,maxrow.second);
			}
			else
			{
				n-=column[maxcolumn.second].first;
				column.erase(maxcolumn.second);
				erase_element(row,maxcolumn.second);
			}
			count++;
		}	
		cout<<count<<endl;
	}
}
