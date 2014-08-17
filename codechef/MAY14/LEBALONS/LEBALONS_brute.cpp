#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<pair<int,int> > balloons(n);
		for(int i=0;i<n;i++)
			cin>>balloons[i].first>>balloons[i].second;
		
		
		int combinations=0;
		int cost=0;
		for(long long i=0;i<(1<<n);i++)
		{
			set<int> colours;
			int currentCost=0;
			
			int	j=0;
			int i_temp=i;
			while(i_temp)
			{
				if(i_temp&1)
				{
					currentCost+=balloons[j].second;	
					colours.insert(balloons[j].first);
				}
				j++;
				i_temp>>=1;
			}
			if(colours.size()>=m)
			{
					cost+=currentCost;
					combinations++;	
			}
			
		}
		cout.setf(ios::fixed);
		cout.precision(6);
		if(combinations==0)
			cout<<0.0<<endl;
		else
		cout<<((double)cost)/combinations<<endl;	
	}
	
}
