#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;


int main()
{
//	freopen("myout.txt","w",stdout);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		vector<pair<int,int> > data;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			string a;
			cin>>a;
			int l=-1,length=0;
			for(int i=0;i<a.size();i++)
			{
				if(l<0&&a[i]=='#')
				{
					l=i;
					length=1;
				}
				
				else if(l>=0&&a[i]=='.')
					break;
					
				else if(l>=0&&a[i]=='#')
					length++;
			}
			data.push_back(make_pair(l,length));
		}
		
		int i=0;
		while(i<data.size()&&data[i].first<0)
			i++;
		
		int previousfirst=-1;
		int previoussecond=-1;
		while(i<data.size()&&data[i].first>=0)
		{
			if(previousfirst<0)
			{
				previousfirst=data[i].first;
				previoussecond=data[i].second;
			}
			else if(data[i].first!=previousfirst||data[i].second!=previoussecond)
			{
				break;
			}
			i++;
		}	
		while(i<data.size()&&data[i].first<0)
			i++;
		cout<<"Case #"<<T<<": "; 
		if(i==data.size())
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
}
