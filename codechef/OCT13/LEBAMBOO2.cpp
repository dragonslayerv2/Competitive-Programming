#include<iostream>
#include<climits>
#include<vector>
using namespace std;

bool odd(const vector<int> &a,const vector<int> &b)
{
	for(int i=0;i<a.size();i++)
	{
		if((a[i]-b[i])%2)
			return true;
	}
}
bool even(const vector<int> &a,const vector<int> &b)
{
	for(int i=0;i<a.size();i++)
	{
		if((((a[i]-b[i])%2))==0)
			return true;
	}
}

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
		
		long long sigmaa=0;
		long long sigmab=0;
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sigmaa+=a[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			sigmab+=b[i];
		}
		
		long long ans=0;
		
		if(n==1)
		{
			if(b[0]<=a[0])
				ans=a[0]-b[0];
			else
				ans=-1;		
		}
		
		else if(n==2)
		{
			if(a[0]-b[0]==b[1]-a[1])
			{	
				ans=a[0]-b[0];
				ans=ans<0?ans*(-1):ans;
			}
			else
				ans=-1;
			
		}
		else
		{
			if((sigmab-sigmaa)%(n-2)==0)
			{
				if(odd(a,b)&&even(a,b))
				{
					ans=-1;
					
				}
				else
				{
					ans=(sigmab-sigmaa)/(n-2);
					for(int i=0;i<n;i++)
					{
						if(b[i]-a[i]>ans)
						{
							ans=-1;
							break;
						}
					}
				}
			}
			else
				ans=-1;
		}
		cout<<ans<<endl;			
	}
}
