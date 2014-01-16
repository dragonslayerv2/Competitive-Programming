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
		vector<int> array(n);
		for(int i=0;i<n;i++)
			cin>>array[i];
		
		sort(array.begin(),array.end());
		
		long long count=0;
		
		size_t lastdifferent=0;
		
		array.push_back(0);
		
		for(size_t i=0;i<array.size()-1;i++)
		{
	//		cout<<array[i]<<" "<<lastdifferent<<endl;
			count+=lastdifferent;
			if(array[i]!=array[i+1])
				lastdifferent=i+1;	
		}
		cout<<count<<endl;
	}
}
