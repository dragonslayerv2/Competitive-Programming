#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//-------------------------------------
	
int main()
{
	int n;
	long long s,e;
	cin>>n>>s>>e;
	vector<pair<long long,long long> > P;
	
	long long x,p;
	for(int i=0;i<n;i++)
	{
		cin>>x>>p;
		
		P.push_back(make_pair((x-p),(x+p)));
	}
	
	long long ans=0;
	sort(P.begin(),P.end());
	
	long long end=s;
	if(P[0].first>s && P[0].first<=e)
	ans+=(P[0].first-s);
	else if(P[0].first>s)
	ans+=(e-s);
	end=max(end,P[0].second);
	for(int i=1;i<n;i++)
	{
		if(end<P[i].first && P[i].first<=e)
		{
			ans=ans+(P[i].first-end);
			
		}
		else if(end<P[i].first)
		{
			ans=ans+(e-end);
		}
		end=max(end,P[i].second);
		if(end>=e)
		break;
	}
	//cout<<end<<endl;
	if(e>end)
	ans+=(e-end);
	cout<<ans<<endl;
}
