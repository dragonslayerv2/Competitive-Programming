#include<iostream>
using namespace std;

int main()
{
	int t1;
	cin>>t1;
	int no[100];
	while(t1--)
	{
		
		int n,k;
		cin>>n>>k;
		while(k--)
		{
			bool flag=true;
			for(int i=0;i<n;i++)
			{
				cin>>no[i];
			}
			int i=0;
			while(i<n-1&&no[i+1]>no[i])
				i++;
			while(i<n-1&&no[i+1]<no[i])
				i++;
		//	cout<<i<<"="<<n-1<<endl;
			if(i!=n-1) flag=false;
			cout<<flag<<endl;
		}
	}
	
	//------------------------------
	
	int t2;
	cin>>t2;
	while(t2--)
	{
		
		int n,k;
		cin>>n;
		cin>>k;
		while(k--)
		{
			long long ans=1;
			int p;
			cin>>p;
			
			for(int i=p+1;i<n;i++)
				ans*=2;
			if(p>n) cout<<0<<endl;
			else    cout<<ans<<endl;
		}
	
	}
	return 0;
}
