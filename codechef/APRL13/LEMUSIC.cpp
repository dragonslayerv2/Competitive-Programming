#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define MAX 100005

struct song
{
	unsigned long long band;
	unsigned long long length;
};

song songs[MAX];

bool cmp(song a,song b)
{
	return a.length<b.length;
}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		unsigned long long sweetness=0;
		int n;
		cin>>n;
		map<unsigned long long,unsigned long long> minlengthsong;
		int distinct=0;
		for(int i=0;i<n;i++)
		{
			cin>>songs[i].band>>songs[i].length;
			
			if(minlengthsong[songs[i].band]==0)
				{
					minlengthsong[songs[i].band]=songs[i].length;
					distinct++;
				}
			else
				{
					minlengthsong[songs[i].band]=min(minlengthsong[songs[i].band],songs[i].length);
				}
		}
		
		unsigned long long ans=0;
		vector<unsigned long long> minlist;
		for(map<unsigned long long,unsigned long long>::iterator i=minlengthsong.begin();i!=minlengthsong.end();i++)
		{
			minlist.push_back((*i).second);
		}
		sort(minlist.begin(),minlist.end());
		
		for(int i=0;i<distinct;i++)
		{
			ans+=minlist[i]*(i+1);
		}
		
		for(int i=0;i<n;i++)
		{
			if(minlengthsong[songs[i].band]==songs[i].length)
				minlengthsong[songs[i].band]=0;
			else
				ans+=songs[i].length*distinct;
		}
		
		cout<<ans<<endl;
	}
		return 0;
}
