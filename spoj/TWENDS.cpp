#include<iostream>
#include<vector>
using namespace std;

int main()
{
//	freopen("test.txt","r",stdin);
	int T=0;
	while(1)
	{
		T++;
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		
		vector<int> A(n);
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		
		vector<vector<int> > DP(n,vector<int>(n));
		
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<n;j++)
			{
				if(i==j)
					DP[i][j]=A[i];
				else if(i>j)
					continue;
				else
				{
					int iTaken=0;
					if(A[i+1]>=A[j])
					{
						if(i+2<=j)
							iTaken=DP[i+2][j];
						iTaken-=A[i+1];
					}
					else
					{
						if(i+1<=j-1)
							iTaken=DP[i+1][j-1];
						iTaken-=A[j];
					}
					
					int jTaken=0;
					if(A[i]>=A[j-1])
					{
						if(i+1<=j-1)
							jTaken=DP[i+1][j-1];
					
						jTaken-=A[i];
					}
					else
					{
						if(i<=j-2)
							jTaken=DP[i][j-2];
						jTaken-=A[j-1];
					}
					
					iTaken+=A[i];
					jTaken+=A[j];
					DP[i][j]=max(iTaken,jTaken);	
				}
				
			}
			
		}
		int optimal=DP.front().back();
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",T,optimal);
	}
}
