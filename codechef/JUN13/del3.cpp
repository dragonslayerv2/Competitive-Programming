#include<iostream>
#include<limits>
using namespace std;



long long abs(long long num)
{
	if(num>=0)
		return num;
	else
		return num*-1;
}

long long a[10200];	
long long max1n[10200];
long long min1n[10200];
long long maxn1[10200];
long long minn1[10200];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
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
				if(a[i]>0) flag=false;
            	max_ending_here+=a[i];
            	if(max_ending_here<0)
            		max_ending_here=0;
            	if(max_ending_here>max_so_far)
            		max_so_far=max_ending_here;   
            	maxn1[i]=max_so_far;
    		}
    	}
    //-----------------kadanes backward min---------------------------------------------------------
	{
			bool flag=true;
    		long long min_so_far=numeric_limits<long long>::max(), min_ending_here=0;
    		for(int i=n-1;i>=0;i--)
    		{
    			if(flag&&a[i]>0)
    			{
    				if(i!=n-1)
						minn1[i]=min(minn1[i+1],a[i]);
					else
						minn1[i]=a[i];
					continue;
				}
				if(a[i]<0) flag=false;
            	min_ending_here+=a[i];
            	if(min_ending_here>0)
            		min_ending_here=0;
            	if(min_ending_here<min_so_far)
            		min_so_far=min_ending_here;   
            	minn1[i]=min_so_far;
    		}
    	}
    	//-----------------kadanes forward min---------------------------------------------------------
		{
			bool flag=true;
    		long long min_so_far=numeric_limits<long long>::max(), min_ending_here=0;
    		for(int i=0;i<n;i++)
    		{
    			if(flag&&a[i]>=0)
    			{
    				if(i!=0)
						min1n[i]=min(min1n[i-1],a[i]);
					else
						min1n[i]=a[i];
					continue;
				}
				if(a[i]<0) flag=false;
            	min_ending_here+=a[i];
            	if(min_ending_here>0)
            		min_ending_here=0;
            	if(min_ending_here<min_so_far)
            		min_so_far=min_ending_here;   
            	min1n[i]=min_so_far;
    		}
    	}
    	long long ans=numeric_limits<long long>::min();
    	for(int i=0;i<n-1;i++)
    	{
			ans=max(ans,abs(max1n[i]-minn1[i+1]));
			ans=max(ans,abs(min1n[i]-maxn1[i+1]));
		}
		if(n==1)
			cout<<a[0]<<endl;
		else
			cout<<ans<<endl;
	}

}
