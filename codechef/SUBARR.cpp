#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class BIT
{
	vector<long long> tree;
	int n;	
	public:
		BIT(size_t size)
		{
			n=size;
			tree.resize(n+1);
		}
		
		long long read(int idx)
		{
			int sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		void increase(int idx, int val)
		{ 
			if(idx<=0)
				return;
			while (idx <= n)
			{ 
				tree[idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
		long long query(int a,int b)
		{
			return read(b)-read(a-1);
		}
};


int main()
{
	int n,k;
	cin>>n>>k;
	vector<pair<long long,int> > prefix(n);
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		a-=k;
		if(!i)
			prefix[i]=make_pair(a,i+1);
		else
			prefix[i]=make_pair(prefix[i-1].first+a,i+1);
	}
	sort(prefix.begin(),prefix.end());
	BIT bit(prefix.size());
	
	long long count=0;
	for(int i=0;i<n;i++)
	{
	//	cout<<"At i"<<endl;
		if(prefix[i].first>=0)
			count++;
		count+=bit.read(prefix[i].second);
		bit.increase(prefix[i].second,1);
	}
	cout<<count<<endl;	
}
