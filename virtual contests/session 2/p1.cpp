#include<iostream>
#include<algorithm>
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
		int one=0;
		int two=0;
		int three=0;
		vector<int> array;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			if(a==1)
				one++;
			else if(a==2)
				two++;
			else if(a==3)
				three++;
			else
				array.push_back(a);
		}
		
		sort(array.rbegin(),array.rend());
		
		while(one--)
			cout<<1<<" ";
		
		if(two&&three&&!array.size())
			cout<<2<<" "<<3;
		
		else if(!three||!two)
		{
			for(int i=0;i<array.size();i++)
				cout<<array[i]<<" ";
			if(two)
				cout<<2;
			if(three)
				cout<<3;
		}
		else 
		{
			for(int i=0;i<array.size();i++)
				cout<<array[i]<<" ";
			
			cout<<3<<" "<<2;
		}
		cout<<endl;
	}
}
