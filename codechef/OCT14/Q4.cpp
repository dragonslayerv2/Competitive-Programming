#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
//---------------------------------------------

int main()
{
	int n;
	cin>>n;
	int ans;
	vector<pair<int,int> > V;
	map<pair<int,int> , int> M;
	if(n==0)
	ans=4;
	if(n==1)
	ans=3;
	else
	ans=2;
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		V.push_back(make_pair(a,b));
		M[make_pair(a,b)]=1;
	}
	int temp=2;
	if(n>1)
	{
		//cout<<ans<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int y1=V[i].second+(V[j].first-V[i].first);
				int x1=V[i].first+(V[i].second-V[j].second);
				int y2=V[j].second+(V[i].first-V[j].first);
				int x2=V[j].first+(V[j].second-V[i].second);
		//		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
				temp=2;
				if(M.find(make_pair(x1,y1))==M.end() &&  M.find(make_pair(x2,y2))==M.end());
				else if(M.find(make_pair(x1,y1))==M.end())
					temp--;
				else if(M.find(make_pair(x2,y2))==M.end())
					temp--;
				else
					temp-=2;
				if(ans>temp)
				ans=temp;
				
				y1=V[i].second-(V[j].first-V[i].first);
				x1=V[i].first-(V[i].second-V[j].second);
				y2=V[j].second-(V[i].first-V[j].first);
				x2=V[j].first-(V[j].second-V[i].second);
				temp=2;
				if(M.find(make_pair(x1,y1))==M.end() &&  M.find(make_pair(x2,y2))==M.end());
				else if(M.find(make_pair(x1,y1))==M.end())
					temp--;
				else if(M.find(make_pair(x2,y2))==M.end())
					temp--;
				else
					temp-=2;
				if(ans>temp)
				ans=temp;
			}
		}
	}
	cout<<ans<<endl;
}
