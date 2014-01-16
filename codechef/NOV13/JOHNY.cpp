#include<iostream>
#include<vector>
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
		
		int k;
		cin>>k;
		k--;
		
		int count=1;
		for(int i=0;i<n;i++)
		{
			if(array[i]<array[k])
				count++;
		}
		cout<<count<<endl;
	}
}
