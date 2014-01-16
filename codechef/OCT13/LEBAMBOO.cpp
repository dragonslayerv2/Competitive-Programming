#include<iostream>
#include<climits>
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
		
		vector<int> a(n);
		vector<int> b(n);
		
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		
		int MIN=INT_MAX;
		long long sum=0;
		bool ispossible=true;
		
		for(int i=1;i<n;i++)
		{
			int difference=(a[i]-a[0])-(b[i]-b[0]);
			if(difference>=0&&difference%2)
			{
				ispossible=false;
				break;
			}
			else if((difference*(-1))%2)
			{
				ispossible=false;
				break;
			}
			difference/=2;
			MIN=min(MIN,difference);
			sum+=difference;
		}
		
		long long ans;
		if(!ispossible)
			ans=-1;
		else
		{
			if(MIN>=0)
				ans=sum;
			else
			{
				ans=sum+n*(MIN*(-1));
			}
		}
		cout<<ans<<endl;
	}
}

