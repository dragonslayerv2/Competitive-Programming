#include<stdio.h>

#define MAX 100

#define max(a,b) a>b?a:b;


inline int solve(int a[MAX][MAX],int n)
{
      int i,j;
      for(i=n-3;i>=0;i--)
      {
              a[n-1][i]+=a[n-1][i+1];
              a[i][n-1]+=a[i+1][n-1];
      }
      
      for(i=n-2;i>=0;i--)
      {
                         for(j=n-2;j>=0;j--)
                                            a[i][j]+=max(a[i+1][j],a[i][j+1]);
      }
      
     // check(a,n);
      return a[0][0];
}
int main()
{
    int i,j;
    int a[MAX][MAX];
    int num[MAX][MAX];
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int n;
              scanf("%d",&n);
              for(i=0;i<n;i++)
              {
                              for(j=0;j<n;j++)
                              {
                                              scanf("%d",&a[i][j]);
                              }
              }
              int ans=solve(a,n);
              if(ans<0)printf("Bad Judges\n"); 
              else printf("%f\n",((float)ans)/(2*n-3));
    }
    return 0;
}
