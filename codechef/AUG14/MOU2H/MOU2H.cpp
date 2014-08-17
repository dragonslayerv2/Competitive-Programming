#include<stdio.h>
#include<vector>

using namespace std;

#define MOD 1000000009LL
#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif

inline int readInt() 
{
	int flag=1;
    int n = 0;
    char c;
    int sign=1;
    while (1)
    { 		
		c=GETCHAR();
    	if(c=='-')	sign=-1;
        else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
        else if(flag!=1) break; 
    }
    return sign*n;
}

inline void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     // buf[10] = 0;
     buf[10] = '\n';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}

#define MAX 3000000
int height[MAX];
int sequence[MAX];

int dp[MAX];
int sum[MAX];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("test.txt","r",stdin);
	#endif
	
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&height[i]);
		
		for(int i=0;i<n-1;i++)
			sequence[i+1]=height[i+1]-height[i];

		
		dp[0]=1;
		sum[0]=1;
		for(int i=1;i<n;i++)
		{
			dp[i]=sum[i-1];
			map<int,int>::iterator lastIterator = lastOccurence.find(sequence[i]);
			
			if(lastIterator!=lastOccurence.end()) 
				dp[i]=(MOD+sum[i-1]-sum[lastIterator->second-1])%MOD;
			
			sum[i]=(sum[i-1]+dp[i])%MOD;
			lastOccurence[sequence[i]]=i;
		}
		printf("%d\n",sum[n-1]-1);
	}	
}
