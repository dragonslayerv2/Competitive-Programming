#include<iostream>
#include<vector>
#include<map>

using namespace std;
typedef pair<int,int> point;
int removerow(vector<point> &points,int row)
{
	map<int,bool> hashmap;
	for(int i=0;i<points.size();i++)
	{
		if(points[i].first!=row)
			hashmap[points[i].second]=true;
	}
	return hashmap.size();
}

int removecolumn(vector<point> &points,int column)
{
	map<int,bool> hashmap;
	for(int i=0;i<points.size();i++)
	{
			if(points[i].second!=column)
				hashmap[points[i].first]=true;
	}
	return hashmap.size();
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
			
		map<int,bool> distinctrows,distinctcolumns;
		for(int i=0;i<points.size();i++)
		{
			distinctrows[points[i].first]=true;
			distinctcolumns[points[i].second]=true;
		}
		
		map<int,int> rowprofit,columnprofit;
		for(map<int,bool>::iterator i=distinctrows.begin();i!=distinctrows.end();i++)
		{
			rowprofit[i->first]=distinctcolumns.size()-removerow(points,i->first);
		}
		
		for(map<int,bool>::iterator i=distinctcolumns.begin();i!=distinctcolumns.end();i++)
		{
			columnprofit[i->first]=distinctrows.size()-removecolumn(points,i->first);
		}
		
		map<int,bool> deletedrow,deletedcolumn;
		int count=0;
		for(int i=0;i<points.size();i++)
		{
			if(!deletedrow[points[i].first]&&!deletedcolumn[points[i].second])
			{
				count++;
				if(rowprofit[points[i].first]>columnprofit[points[i].second])
					deletedrow[points[i].first]=true;
				else
					deletedcolumn[points[i].second]=true;
			}
		}
		cout<<count<<endl;
	}

}
