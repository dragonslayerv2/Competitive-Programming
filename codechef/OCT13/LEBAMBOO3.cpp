#include<iostream>
#include<vector>
#include<climits>
using namespace std;


bool even(vector<int> &A,vector<int> &B)
{
	for(int i=0;i<A.size();i++)
	{
		if((A[i]-B[i])%2)
			return true;
	}
	return false;
}

bool odd(vector<int> &A,vector<int> &B)
{
	for(int i=0;i<A.size();i++)
	{
		if(((A[i]-B[i])%2)==0)
			return true;
	}
	return false;
}

long long getsum(vector<int> &A)
{
	long long sum=0;
	for(int i=0;i<A.size();i++)
		sum+=A[i];
	return sum;
}

int getmax(vector<int> &A,vector<int> &B)
{
	int MAX=INT_MIN;
	for(int i=0;i<A.size();i++)
	{
		MAX=max(MAX,B[i]-A[i]);
	}	
	return MAX;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<int> a,b;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			a.push_back(temp);
		}
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			b.push_back(temp);
		}
		
		long long ans;
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
				if(ans<0)
					ans*=-1;
			}
			else
				ans=-1;
		}
		else
		{
			long long suma=getsum(a);
			long long sumb=getsum(b);
			if(even(a,b)&&odd(a,b))
			{
				ans=-1;
			}
				
			else if(((sumb-suma)%(n-2))==0)
			{
				ans=(sumb-suma)/(n-2);
				if(getmax(a,b)>ans)
				{
					ans=-1;
				}
			}
			else
				ans=-1;			
		}
		cout<<ans<<endl;
	}
}
