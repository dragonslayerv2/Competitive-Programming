#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<int> stickcount(500);
		
		vector<int> pos(500);
		vector<int> h(500);
		
		for(int i=0;i<n;i++)
		{
			cin>>pos[i]>>h[i];
			pos[i]+=200;
			stickcount[pos[i]]++;
		}
		
		for(int i=1;i<=stickcount.size();i++)
			stickcount[i]+=stickcount[i-1];
			
		for(int i=0;i<n;i++)
		{
			cout<<stickcount[pos[i]+h[i]]-stickcount[pos[i]-1]<<" ";
		}
		
	}
}
