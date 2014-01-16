#include<iostream>

#include<climits>
using namespace std;

long long a[10000];		

pair<long long,long long> maxsubarray(long long a[],long long mini,long long maxi)
{
    pair<long long,long long> maxpos(-1,-1);
	
	long long max_so_far=INT_MIN, max_ending_here=0;
    long long count=0;
    for(long long i=mini;i<=maxi;i++)
    {       
		count++;
		max_ending_here+=a[i];
        if(max_ending_here<0)
		{
			max_ending_here=0;
			count=0;
		}
        if(max_ending_here>max_so_far)
        {	
			max_so_far=max_ending_here;
			maxpos.second=i;
			maxpos.first=maxpos.second-count+1;
		}
    }
    return maxpos;
}


pair<long long,long long> minsubarray(long long a[],long long mini,long long maxi)
{
    pair<long long,long long> minpos(-1,-1);
	
	long long min_so_far=INT_MAX, min_ending_here=0;
    long long count=0;
    for(long long i=mini;i<=maxi;i++)
    {       
		count++;
		min_ending_here+=a[i];
        if(min_ending_here>0)
		{
			min_ending_here=0;
			count=0;
		}
        if(min_ending_here<min_so_far)
        {	
			min_so_far=min_ending_here;
			minpos.second=i;
			minpos.first=minpos.second-count+1;
		}
    }
    return minpos;
}



long long abs(long long num)
{
	if(num>=0)
		return num;
	else
		return num*-1;
}

bool disjoint(pair<long long,long long> a,pair<long long,long long> b)
{
	if(a.first>=b.first&& a.second<=b.second)	
		return false;
	else if(b.first>=a.first&& b.second<=a.second)	
		return false;
	else
		return true;
}


long long getans(long long a[],pair<int,int> p,pair<int,int> q)
{
	long long sum=0;
	for(int i=p.first;i<=p.second;i++)
		sum+=a[i];
	for(int i=q.first;i<=q.second;i++)
		sum-=a[i];
	return abs(sum);	
	
}
void display(pair<int,int> a)
{
	cout<<"("<<a.first<<","<<a.second<<")";
}
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long neg=0;
		long long pos=0;
		long long sum=0;
		
		for(long long i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]>0)
				pos++;
			else if(a[i]<0)
				neg++;
			
			sum+=a[i];
			
		}	
		long long ans=0;
		if(n==2)
			ans=abs(a[0]-a[1]);
		else if(neg==0||pos==0)
		{
			long long lsum=0;
			long long rsum=sum;
			for(long long i=0;i<n;i++)
			{			
				rsum=rsum-a[i];
				if(i>0)
					ans=max((long long)abs(lsum-a[i]),ans);
				ans=max((long long)abs(rsum-a[i]),ans);
				lsum=lsum+a[i];
			}
		}

		else
		{
			pair<long long,long long> maxpos=maxsubarray(a,0,n-1);
			pair<long long,long long> minpos=minsubarray(a,0,n-1);
			if(disjoint(maxpos,minpos))
			{
				for(int i=maxpos.first;i<=maxpos.second;i++)
					ans+=a[i];
				for(int i=minpos.first;i<=minpos.second;i++)
					ans-=a[i];
				ans=abs(ans);
			}
			else
			{
				
				pair<int,int> minleft=minsubarray(a,0,maxpos.first-1);
				pair<int,int> minright=minsubarray(a,maxpos.second+1,n-1);
				pair<int,int> maxleft=maxsubarray(a,0,minpos.first-1);
				pair<int,int> maxright=maxsubarray(a,minpos.second+1,n-1);
			/*	cout<<"minpos = ";display(minpos);
				cout<<"maxpos = ";display(maxpos);
				cout<<"minleft = ";display(minleft);
				cout<<"minright = ";display(minright);
				cout<<"maxleft = ";display(maxleft);
				cout<<"maxright = ";display(maxright);*/
				
				if(maxpos.first-1>=0)		
						ans=max(ans,getans(a,minleft,maxpos));
					
				if(minpos.first-1>=0)
						ans=max(ans,getans(a,maxleft,minpos));	
					
				if(maxpos.second+1<=n-1)
						ans=max(ans,getans(a,maxpos,minright));
						
				if(minpos.second+1<=n-1)
						ans=ans=max(ans,getans(a,minpos,maxright));
			}
		}
		cout<<abs(ans)<<endl;
	}

}
