#include<iostream>
#include<deque>
using namespace std;


int main()
{
	int n;
	cin>>n;
	
	deque<long long> array(n);
	deque<long long> suffix_sum(n+1);
	for(int i=0;i<n;i++)
		cin>>array[i];
	
	for(int i=n-1;i>=0;i--)
		suffix_sum[i]=suffix_sum[i+1]+array[i];
	
	int q;
	cin>>q;
	while(q--)
	{
		int command;
		cin>>command;
		if(command==1)
		{
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			cout<<suffix_sum[l]-suffix_sum[r+1]<<endl;
		}
		else
		{
			long long number;
			cin>>number;
			array.push_front(number);
			suffix_sum.push_front(number+suffix_sum.front());
		}
	}
}
