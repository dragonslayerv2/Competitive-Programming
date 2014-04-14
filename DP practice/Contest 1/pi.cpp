#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

//-------------------------------
struct order
{
	int st,d,p;
	order(int S=0,int D=0,int P=0)
	{
		st=S;
		d=D;
		p=P;
	}
	bool operator <(const order &b)const
	{
		return st<b.st;
	}	
};
int main()
{
	int t;
	scanf("%d",&t);
	
	vector<int> DP(10000);
	vector<int> maxSuffix(1000001);
	while(t--)
	{
		DP.clear();
		maxSuffix.clear();
		maxSuffix.resize(1000000);
		
		int n;
		DP.resize(n);
		scanf("%d",&n);
		vector<order> O(n);
		for(int i=0;i<n;i++)
			scanf("%d %d %d",&O[i].st,&O[i].d,&O[i].p);
		
		sort(O.begin(),O.end());
		for(int i=n-1;i>=0;i--)
		{
			DP[i]=O[i].p;
			
			if(O[i].st+O[i].d<1000000)
				DP[i]=max(DP[i],O[i].p+maxSuffix[O[i].st+O[i].d]);	

			if(i!=n-1)
				DP[i]=max(DP[i],DP[i+1]);
			
			maxSuffix[O[i].st]=max(maxSuffix[O[i].st],DP[i]);
			if(O[i-1].st!=O[i+1].st)
			{
				for(int j=O[i-1].st;j<=O[i].st;j++)
					maxSuffix[j]=max(maxSuffix[j],DP[i]);
			}
		}
		printf("%d\n",DP[0]);
	}
}
