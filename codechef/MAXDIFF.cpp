#include<iostream>
#include<queue>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		if(k>n-k)
			k=n-k;
		long long sum=0;
		priority_queue<int> min_weights;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			sum+=a;
			min_weights.push(a);
		//	cout<<min_weights.top();
			if(min_weights.size()>k)
				min_weights.pop();
		}
		long long sum2=0;
		while(!min_weights.empty())
		{
			sum2+=min_weights.top();
			min_weights.pop();
		}
		cout<<sum-2*sum2<<endl;
	}
}
