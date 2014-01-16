#include<iostream>
#include<vector>
#include<map>

using namespace std;
typedef pair<int,int> point;

int removeprofit(map<int,map<int,bool> > &A,map<int,map<int,bool> > &B,int x)
{
	int count=0;
	for(map<int,bool>::iterator i=A[x].begin();i!=A[x].end();i++)
	{
		if(B[i->first].size()==1)
			count++;
	}
	return count;
}

void remove(map<int,map<int,bool> > &A,map<int,map<int,bool> > &B,int x)
{
	for(map<int,bool>::iterator i=A[x].begin();i!=A[x].end();i++)
	{
		B[i->first].erase(x);
		if(!B[i->first].size())
			B.erase(i->first);
	}
	A.erase(x);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<point> points(n);
		
		for(int i=0;i<n;i++)
			cin>>points[i].first>>points[i].second;

		map<int,map<int,bool> > rows;
		map<int,map<int,bool> > columns;
		for(int i=0;i<points.size();i++)
		{
			rows[points[i].first][points[i].second]=true;
			columns[points[i].second][points[i].first]=true;
		}
		
		
		
		map<int,bool> deletedrow,deletedcolumn;
		int count=0;
		for(int i=0;i<points.size();i++)
		{
			
			if(!deletedrow[points[i].first]&&!deletedcolumn[points[i].second])
			{
				count++;
				
				int rowprofit=removeprofit(rows,columns,points[i].first);
				int columnprofit=removeprofit(columns,rows,points[i].second);
				
				if(rowprofit>columnprofit)
				{
					remove(rows,columns,points[i].first);
					deletedrow[points[i].first]=true;
				}
				else
				{
					remove(columns,rows,points[i].second);
					deletedcolumn[points[i].second]=true;
				
				}
			}
		}
		cout<<count<<endl;
	}
}

