#include<iostream>
#include<vector>
using namespace std;

#define MAX 1000005
bool win[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	int k,l,m;
	cin>>k>>l>>m;
	
	for(int i=1;i<MAX;i++)
	{
		bool lose=false;
		if(i-1>=0)
			lose|=!win[i-1];
		if(i-k>=0)
			lose|=!win[i-k];
		if(i-l>=0)
			lose|=!win[i-l];
		
		win[i]=lose;
	}
	while(m--)
	{
		int n;
		cin>>n;
		cout<<(win[n]?"A":"B");
	}
}
