#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;


class clock
{
	vector<bool> time;
	public:
		clock(int n)
		{
			time.resize(n);
		}
		bool occupy(int pos)
		{
			pos--;
			while(pos>-1&&time[pos])
				pos--;
			if(pos==-1)
				return false;
			else
			{
				time[pos]=true;
				return true;
			}
		}
};

bool cmp(const pair<int,int> &b,const pair<int,int> &a)
{
	if(a.second<b.second)
		return true;
	else if(a.second>b.second)
		return false;
	else 
		return a.first>b.first;
}
int main()
{
	vector<pair<int,int> > timeslots;
	int n;
	cin>>n;
	timeslots.resize(n);
	int MAX=INT_MIN;
	for(int i=0;i<timeslots.size();i++)
	{
		cin>>timeslots[i].first>>timeslots[i].second;
		MAX=max(timeslots[i].first,MAX);
	}
	
	sort(timeslots.begin(),timeslots.end(),cmp);
	int profit=0;
	clock C(MAX);
	
	for(int i=0;i<timeslots.size();i++)
	{
		cout<<"Checking for"<<timeslots[i].first<<" "<<timeslots[i].second;
		if(C.occupy(timeslots[i].first))
		{
			cout<<"Took";
			profit+=timeslots[i].second;
		}
		cout<<endl;
	}
	cout<<profit;
	
}
