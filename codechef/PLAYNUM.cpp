#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int q;
		cin>>q;
		vector<int> numbers;
		numbers.resize(n+1,0);
		
		for(int i=1;i<numbers.size();i++)
			cin>>numbers[i];

		
		
		vector<int> increment(n+1,0);
		while(q--)
		{
			int a,b;
			cin>>a>>b;
			increment[a-1]++;
			increment[b]--;
		}
		
		vector<int> frequency(n+1,0);
		
		int current=increment[0];
		for(int i=1;i<frequency.size();i++)
		{
			frequency[i]+=current;
			current+=increment[i];
		}
		
		sort(frequency.begin(),frequency.end());
		sort(numbers.begin(),numbers.end());
		long long ans=0;
		for(int i=1;i<frequency.size();i++)
		{
			ans+=frequency[i]*numbers[i];
		}
		cout<<ans<<endl;
		
	}
}
