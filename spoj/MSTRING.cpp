#include<iostream>
#include<vector>
using namespace std;

#define INVALID 10000
#define hash(a) (a-'a')

int main()
{
//	freopen("testMString.txt","r",stdin);
//	ios_base::sync_with_stdio(false);
	
	string a,b;
	cin>>a>>b;
	vector<vector<int> > suffixOccurence(b.size(),vector<int>(27,-1));
	
	
	suffixOccurence[b.size()-1][hash(b[b.size()-1])]=b.size()-1;
	

	for(int i=b.size()-2;i>=0;i--)
	{
		suffixOccurence[i]=suffixOccurence[i+1];
		suffixOccurence[i][hash(b[i])]=i;
	}
	
	
	vector<vector<int> > DP(a.size()+1,vector<int>(b.size()+1,INVALID));
	
	for(int i=0;i<a.size();i++)
		DP[i][b.size()]=1;
		
	for(int i=a.size()-1;i>=0;i--)
		for(int j=b.size()-1;j>=0;j--)
		{
			if(suffixOccurence[j][hash(a[i])]==-1)
				DP[i][j]=1;
			else
			{
				DP[i][j]=min(INVALID,1+DP[i+1][suffixOccurence[j][hash(a[i])]+1]);
				
			}	
			DP[i][j]=min(DP[i][j],DP[i+1][j]);	
		}
	
/*	for(int i=0;i<=a.size();i++)
	{
		for(int j=0;j<=b.size();j++)
			cout<<DP[i][j]<<"\t";
		cout<<endl;
	}*/
	cout<<DP[0][0];
}
