#include<iostream>
#include<queue>
using namespace std;


int main()
{
	int n;
	cin>>n;
	
	priority_queue<int> negative_coins;
	while(n--)
	{
		long long a;
		cin>>a;
		if(a<0)
			negative_coins.push(a);
	}
	long long x;
	cin>>x;
	
	//-------------------------------------------------
	
	
	long long increment=0;
	long long cost=0;
	
	while(!negative_coins.empty())
	{
		if(negative_coins.size()>=x)
		{	
			cost+=x*((negative_coins.top()+increment)*(-1));
			increment+=(negative_coins.top()+increment)*(-1);		
			while(negative_coins.top()+increment>=0)
				negative_coins.pop();
		}
		
		else
		{
			cost+=(-1)*(negative_coins.top()+increment);
			negative_coins.pop();
		}
	}
	cout<<cost;
}
