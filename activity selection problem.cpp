#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp_activity(const pair<int,int> &a,const pair<int,int> &b)
{
	return a.second<b.second;
}

ostream & operator <<(ostream& stream,pair<int,int> activity)
{
	stream<<"("<<activity.first<<", "<<activity.second<<")";
	return stream;
}
int main()
{
	vector<pair<int,int> > activity;
	int n;
	cin>>n;
	while(n--)
	{
		int start,finish;
		cin>>start>>finish;
		activity.push_back(make_pair(start,finish));
	}
	sort(activity.begin(),activity.end(),cmp_activity);
	
	int lastselected=0;
	cout<<activity[lastselected]<<endl;
	for(int i=0;i<activity.size();i++)
	{
		if(activity[i].first>=activity[lastselected].second)
		{
			lastselected=i;
			cout<<activity[lastselected]<<endl;
		}
	}
}
