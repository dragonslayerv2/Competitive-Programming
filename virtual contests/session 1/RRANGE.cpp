#include<iostream>
#include<vector>
using namespace std;

#define MOD 10000

bool intersects(size_t query_left,size_t query_right,size_t node_left,size_t node_right) 
	{
	if(node_left > node_right || node_left > query_right || node_right < query_left) // Current segment is not within range [i, j]
		return false;
	return true;
}

long long sum(long long a,long long terms)
{
	long long first=2*a+(terms-1);
	long long second=terms;	
	
	if((first%2)==0)
		first/=2;
	else
		second/=2;
	return ((first%MOD)*(second%MOD))%MOD;
}

int main()
{
	long long n;
	cin>>n;
	int u,q;
	cin>>u>>q;
	
	vector<pair<long long,long long> > update;
	while(u--)
	{
		long long a,b;
		cin>>a>>b;
		update.push_back(make_pair(a,b));
	}
	
	while(q--)
	{
		long long a,b;
		cin>>a>>b;
		
		long long solution=0;
		for(int i=0;i<update.size();i++)
		{
			if(intersects(update[i].first,update[i].second,a,b))
			{
				if(a>=update[i].first&&b>=update[i].second)
				{
					solution+=sum(a-update[i].first+1,update[i].second-a+1);
				}
				else if(a<=update[i].first&&update[i].second<=b)
				{
					solution+=sum(1,update[i].second-update[i].first+1);
				}
				else if(a<=update[i].first&&b<=update[i].second)
				{
					solution+=sum(1,b-update[i].first+1);
				}
				else if(a==update[i].first&&b==update[i].second)
				{
					solution+=sum(1,update[i].second-update[i].first+1);
				}
				else if(a>=update[i].first&&b<=update[i].second)
				{
					solution+=sum(a-update[i].first+1,b-a+1);
				}
				solution%=MOD;
			}
		}	
		cout<<solution<<endl;
	}
}
