#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100005

struct song
{
	long long band;
	long long length;
};

song songs[MAX];

bool cmp(song &a,song &b)
{
	return a.length<b.length;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long sweetness=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
				cin>>songs[i].band>>songs[i].length;
			
		sort(songs,songs+n,cmp);
		bool bands[MAX]={false};	
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(!bands[songs[i].band])
			{
				bands[songs[i].band]=true;
				count++;
			}
			sweetness+=count*songs[i].length;
		}
		cout<<sweetness;
	}
	return 0;
}
