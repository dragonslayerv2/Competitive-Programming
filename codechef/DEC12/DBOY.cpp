#include<stdio.h>
#include<limits.h>
#define M 501

#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

#define GETCHAR getchar//_unlocked
#define PUTCHAR putchar//_unlocked

inline int readInt() 
{
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c=='\n'||c==' ') break;
                              n = n * 10 + c - '0';
    }
    return n;
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


int main()
{
    int t;
    t=readInt();
    while(t--)
    {
              int n,i,j;
              int h[M];
              int knapsack[2*M];
              int max=0;
              n=readInt();
              
              for(i=0;i<n;i++)
              {
                        h[i]=readInt();
                        max=MAX(max,h[i]);
              }
              max*=2;
              for(i=0;i<=max;i++)
              {
                      knapsack[i]=0;
              }
              
              for(i=0;i<n;i++)
              {
                      
                      
                      knapsack[readInt()]=1;
              }
              
              for(i=1;i<=max;i++)
              {
                                 if(knapsack[i]==1) continue;
                                 else
                                 {
                                                   knapsack[i]=10000;
                                                   for(j=1;j<=i/2;j++)
                                                   {
                                                                     if(!knapsack[j]||!knapsack[i-j]) continue;
                                                                     knapsack[i]=MIN(knapsack[i], knapsack[j]+knapsack[i-j]);
                                                   }
                                 }
              }
          /*    
              for(int i=0;i<=max;i++)
              {
                      printf("%d ",knapsack[i]);
              }
              printf("\n");*/
              int ans=0;
              for(i=0;i<n;i++)
              {
                              
                     //   printf("adding %d for %d\n",knapsack[h[i]],2*h[i]);
                        ans+=knapsack[2*h[i]];
              }
              
              writeInt(ans);
    }  
    return 0;
}
