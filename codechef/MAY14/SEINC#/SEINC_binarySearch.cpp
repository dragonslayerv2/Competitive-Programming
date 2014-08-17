#include<iostream>
#include<limits>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

vector<int> a;

#define MAXDP 3
int DP[100100][MAXDP];

vector<int> solveHash;
int solve(int base)
{
	if(base<0)
		return numeric_limits<int>::max();
	
	if(solveHash[base]!=-1)
		return solveHash[base];
	else
	{
	//	cout<<"Solving for "<<base;
		for(int i=0;i<MAXDP;i++)
			DP[a.size()][i]=0;
		
				
		for(int i=a.size()-1;i>=1;i--)
		{
			for(int j=0;j<MAXDP;j++)
			{
				DP[i][j]=numeric_limits<int>::max();
				for(int k=j-1;k<j+2;k++)
				{
					if(k<0||k>=MAXDP)
						continue;
					DP[i][j]=min(DP[i][j],a[i]+4*(base+k)+DP[i+1][k]-min(a[i]+4*(base+k),a[i-1]+4*(base+j)));
				}		
			}
		}
		
		int ans=numeric_limits<int>::max();
		for(int i=0;i<MAXDP;i++)
			ans=min(ans,DP[1][i]+a[0]+4*(base+i));
	//	cout<<"Returing "<<ans<<endl;
		solveHash[base]=ans;
		return ans;
	}
}


#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif
	
inline int readlong() 
{
	int flag=1;
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
    }
    return n;
}

int unimodularArray(int low,int high)
{
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(solve(mid-1)>solve(mid)&&solve(mid+1)>solve(mid)) return mid;
    else if(solve(mid+1)<solve(mid)) return unimodularArray(mid+1,high);
    else return unimodularArray(low,mid-1);
}

int main()
{
//	freopen("binaryTest.txt","r",stdin);
	int t;
	t=readlong();
	while(t--)
	{
			solveHash.assign(1000,-1);
			int n;
			n=readlong();
			a.resize(n);
			for(int i=0;i<n;i++)
				a[i]=readlong();
		
			for(int i=0;i<n;i++)
			{
				int b;
				b=readlong();
				a[i]=(4+b-a[i])%4;
			}
			
			int ans=solve(unimodularArray(0,100));
			cout<<ans<<endl;
	}
}
