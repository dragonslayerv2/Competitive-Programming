#include<stdio.h>
#include<limits.h>

#define GETCHAR getchar//_unlocked

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

inline int ispossible(int a[],int n,int c)
{
       int k;
       long long left=0;
       for(k=0;k<n;k++)
       {
                       if(a[k]+left-c<(long long)0)
                       {
                                         return 0;
                       }
                       left=a[k]-c+left;  
       }
       return 1;
}
int main()
{
    int t;
    t=readInt();
    while(t--)
    {
              int n;
              n=readInt();
              int c[10010];
              
              int j,i;
              int k=0;
              for(i=0;i<n;i++)
              c[i]=readInt();
                
              int min=c[0];
              int max=c[0];
              int mid;
              long long sum=0;
              for(j=1;j<n;j++)
              {
                              sum+=c[j];
                              if(c[j]<min)
                                          min=c[j];
                              if(c[j]>max)
                                          max=c[j];
              }        
              
              int flag=0;
              if(min==c[0]||n==1) 
                            flag=c[0];
              else
              {
              while(min<=max)
              {
                    mid=(min+max)/2;
                    
                    if(ispossible(c,n,mid))
                    {
                                          flag=mid;
                                          min=min+1;
                                          if(!ispossible(c,n,mid+1))break;
                    }        
                    else
                             max=mid-1;
              }
              }              
              printf("%d\n",flag);
    }
    return 0;
}
