//Dijkstra's Algorithm  Array Version.... 
#include<stdio.h>
#include<limits.h>
 #include<string.h>

#define MAX 4

int W[MAX][MAX]={{0,1,2,0},{-1,0,0,1},{-1,-1,0,-1},{1,1,1,0}};
int d[MAX];
int flags[MAX/32+1];


// bit flags=-----

#define isSet(n) (flags[n>>5]&(1<<(n&31)))
#define unset(n) flags[n>>5] &= ~(1<<(n&31))
#define set(n) flags[n>>5]|=(1<<(n&31))

#define isSet(n) (flags[n>>5]&(1<<(n&31)))
#define unset(n) flags[n>>5] &= ~(1<<(n&31))
#define set(n) flags[n>>5]|=(1<<(n&31))
//------------ min value---------

#define min(a,b) a<=b?a:b
//----------------------------------------

//----------------------------------------------------------

void dijiktra(int s,int n,int W[MAX][MAX],int d[])
{
    int i;
    for(i=0;i<n;i++)
                          d[i]=INT_MAX;
    memset(flags,-1,n*sizeof(*flags));
    d[s]=0;
    for(i=0;i<n;i++)
    {
                      int minpos=-1;
                      for(int j=0;j<n;j++)
                      {
                              if(minpos==-1 && isSet(j)) minpos=j;
                              else if(isSet(i)&&d[j]<d[minpos]) minpos=j;
                      }
                      unset(minpos);
                      for(int j=0;j<n;j++)
                      {
                              if(W[minpos][j]==-1||!(isSet(j))) continue;
                              else
                              {
                                  d[j]=min(d[j],d[minpos]+W[minpos][j]);
                              }                              
                      }
    }
}

int main()
{
    dijiktra(3,4,W,d);
    for(int i=0;i<4;i++)
    {
            printf("%d ", d[i]);
    }
    getchar();
}
