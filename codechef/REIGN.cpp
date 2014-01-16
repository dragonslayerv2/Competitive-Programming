#include<iostream>
#include<vector>
#include<limits>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		vector<long long> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		vector<long long> maxn1(n),max1n(n);
		//--------------- kadanes max forward---------------------------------------
		{
			bool flag=true;
			long long max_so_far=numeric_limits<long long>::min(), max_ending_here=0;
			for(int i=0;i<n;i++)
			{
				if(flag&&a[i]<=0)
				{
					if(i!=0)
						max1n[i]=max(max1n[i-1],a[i]);
					else
						max1n[i]=a[i];
					continue;
				}
				if(a[i]>0) flag=false;
				max_ending_here+=a[i];
				if(max_ending_here<0)
					max_ending_here=0;
				if(max_ending_here>max_so_far)
					max_so_far=max_ending_here;
				max1n[i]=max_so_far;
			}
		}
	//----------------------kadanes max backward------------------------------------
		{
			bool flag=true;
			long long max_so_far=numeric_limits<long long>::min(), max_ending_here=0;
			for(int i=n-1;i>=0;i--)
			{
				if(flag&&a[i]<=0)	
				{
					if(i!=n-1)
						maxn1[i]=max(maxn1[i+1],a[i]);
					else
						maxn1[i]=a[i];
				continue;
			}
			if(	a[i]>0) flag=false;
			max_ending_here+=a[i];
			if(max_ending_here<0)
				max_ending_here=0;
			if(max_ending_here>max_so_far)
				max_so_far=max_ending_here;
				maxn1[i]=max_so_far;
			}
		}
		long long result=numeric_limits<long long>::min();
		for (int i = 0; i < (n - k) - 1; i++) 
			result=max(result,max1n[i]+maxn1[i+k+1]);
		cout<<result<<endl;
	}
}
