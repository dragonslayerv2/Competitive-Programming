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
		int x=0;
		int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(M.find(make_pair(a,b))==M.end())
		{
			x++;
			V.push_back(make_pair(a,b));
			M[make_pair(a,b)]=1;
		}
	}
	
	n=x;
	if(n==0)
	ans=4;
	else if(n==1)
	ans=3;
	else
	ans=2;
	int temp=2;
	if(n>1)
	{
		//cout<<ans<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				
				
				double xc=V[i].first+V[j].first;
				double yc=V[i].second+V[j].second;
				double xd=V[i].first-V[j].first;
				double yd=V[i].second-V[j].second;
				
				int x1= xc - yd  ;  
				int y1 = yc + xd; 
  				int x2 = xc + yd  ;  
				int y2 = yc - xd; 
				
				if(x1%2==1 || x2%2==1 || y1%2==1 || y2%2==1);
				else
				{
					x1/=2;
					y1/=2;
					x2/=2;
					y2/=2;
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
	}
	cout<<ans<<endl;
}
