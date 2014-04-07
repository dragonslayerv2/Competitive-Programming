#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int hSize,vSize;
		scanf("%d %d",&hSize,&vSize);
		
		hSize--;
		vSize--;
		
		vector<int> H(hSize),V(vSize);
		
		for(int i=0;i<hSize;i++)
			scanf("%d",&H[i]);
		
		for(int i=0;i<vSize;i++)
			scanf("%d",&V[i]);
		
		sort(H.begin(),H.end());
		sort(V.begin(),V.end());
		vector<int> pV(vSize+1);
		vector<int> pH(hSize+1);
		
		pH[0]=pV[0]=0;
		for(int i=1;i<pV.size();i++)
			pV[i]=pV[i-1]+V[i-1];
		
		for(int i=1;i<pH.size();i++)
			pH[i]=pH[i-1]+H[i-1];
		
		vector<vector<int> > DP(H.size()+1,vector<int>(V.size()+1));
		
		for(int i=H.size();i>=0;i--)
			for(int j=V.size();j>=0;j--)
			{
				if(i==H.size()&&j==V.size())
					DP[i][j]=0;
				else if(i==H.size())
					DP[i][j]=pH[i]+V[j]+DP[i][j+1];
				else if(j==V.size())
					DP[i][j]=pV[j]+H[i]+DP[i+1][j];
				else
					DP[i][j]=min(pH[i]+V[j]+DP[i][j+1],pV[j]+H[i]+DP[i+1][j]);
			}
		printf("%d\n",DP[0][0]);
	}
}
