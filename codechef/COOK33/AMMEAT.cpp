#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		unsigned long long m;
		cin>>n>>m;
		vector<unsigned long long> p(n);
		for(int i=0;i<n;i++)
			cin>>p[i];
		
		sort(p.begin(),p.end());
		
		unsigned long long x=0;
		int i;
		for(i=n-1;i>=0;i--)
		{
			x+=p[i];
			if(x>=m)
				break;
		}
		
		if(x>=m)
			cout<<n-i;
		else
			cout<<-1;
		cout<<endl;
		
	
	}
	return 0;
}
