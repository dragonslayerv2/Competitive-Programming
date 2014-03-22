#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0;i<a.size();i++)
		cin>>a[i];
	
	vector<pair<int,int> > operations;
	
	for(int i=0;i<a.size();i++)
	{
		int min_pos=i;
		int min=a[i];
		for(int j=i+1;j<a.size();j++)
			if(a[j]<min)
			{
				min=a[j];
				min_pos=j;
			}
		if(min_pos!=i)
		{
			operations.push_back(make_pair(i,min_pos));	
			for(int l=i,r=min_pos;l<r;l++,r--)
				swap(a[l],a[r]);
		}
	}
	cout<<operations.size()<<endl;
	for(int i=0;i<operations.size();i++)
		cout<<1+operations[i].first<<" "<<1+operations[i].second<<endl;
}
