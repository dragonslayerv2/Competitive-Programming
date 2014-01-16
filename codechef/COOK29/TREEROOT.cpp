#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<conio.h>
#include<time.h>
#include<limits.h>
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int roots[100];
int z=0;
void recurse(int N[],int S[],int val[],int n,int i,int child,int v)
{
    int j,k;
    int x;
    if(n==1)
            {roots[z++]=0; return;}
    else if(i==n&&child==n-1)
    {
            roots[z++]=v;
            return;
            
    } 

    else if(S[i]==0) return recurse(N,S,val,n,i+1,child,v);
    else
    {
            for(j=0;j<n;j++)
            {
                    int flag=0;
                    
                    if(j==i||val[j]){continue;}
                    if(N[j]==S[i])
                    {
                                  val[j]=1;
                                  recurse(N,S,val,n,i+1,child+1,v-j);
                                  val[j]=0;
                                  continue;             
                    }
                    for(k=j+1;k<n;k++)
                    {
                            
                            if(k==i||val[k]) {continue;}
                            if(N[k]+N[j]==S[i])
                            {
                                              val[j]=val[k]=1;
                                              recurse(N,S,val,n,i+1,child+2,v-j-k);
                                                                    val[j]=val[k]=0;
                            }
                    }
            }
    } 
}

int main()
{
    int N[100],S[100];
    int val[31];
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
              z=0;
              memset(val,0,sizeof(val));
              memset(roots,0,sizeof(roots));
              
              int n;
              scanf("%d",&n);
              
              for(i=0;i<n;i++)
                      scanf("%d %d",&N[i],&S[i]);
              
              recurse(N,S,val,n,0,0,(n*(n-1))/2);
              
              qsort (roots, z, sizeof(int), compare);
              
              for(i=0;i<z;i++)
              {
                              if(i!=0&&roots[i]==roots[i-1]) continue;
                              printf("%d ",N[roots[i]]);
              }
              
              printf("\n");
    }
    return 0;
}
