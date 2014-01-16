#include<iostream>
#include<limits>
#include<vector>
using namespace std;

long long getL(long long n,long long D,vector<long long> &d, vector<long long> &c)
{
	int L=0;
	int 		start=0;
	//cout<<"At "<<start;
	while(start<n)
	{
		long long D_temp=D;
		while(D_temp>=d[start]&&start<n)
		{
			D_temp-=d[start];
			start++;
		}
		L++;
		//cout<<"-->"<<start;
	}
	//cout<<"-->"<<start;
	return L;
}
long long DFS(long long N,long long D,vector<long long> &d,vector<long long> &c,vector<long long> &s, int L,int days=0,long long i=0)
{
	if(s[N-1]-s[i-1]<=D&&days==L)
		return 0;
	else if(days>=L)
		return numeric_limits<long long>::max();	
	else
	{
		long long travel_cost=0;
		long long MIN=numeric_limits<long long>::max();
		for(long long j=i+1;j<N;j++)
		{
			travel_cost+=d[j];
			if(travel_cost>D)
			{
				break;
			}
			else
			{
				MIN=min(MIN,DFS(N,D,d,c,s,L,days+1,j));	
			}
		}
		return max(MIN,c[i]);
	}
}



int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long N,D;
		cin>>N>>D;
		vector<long long> d,c;
		vector<long long> s;
		d.reserve(N); 
		c.reserve(N);
		s.reserve(N);
		
		d.push_back(0);
		c.push_back(0);
		s.push_back(0);
		
		for(long long i=0;i<N;i++)
		{
			long long d_temp;
			cin>>d_temp;
			d.push_back(d_temp);
			s.push_back(d_temp+s.back());
			long long c_temp;
			cin>>c_temp;
			c.push_back(c_temp);
		}
		N++;
		
		long long L=getL(N,D,d,c);
		cout<<L<<" "<<DFS(N,D,d,c,s,L)<<endl;
	}
}
