#include<stdio.h>

inline int answer(char a[],int n,int i=0)
{
       int count=0;      
       if(i==n)
       {
               if(a[n-1]==a[0]) return 0;
               else             return 1;
       } 
       
       
       else
       {
           for(int j=1;j<=4;j++)
           {                  
                   if(i==0||j!=a[i-1])
                   {
                               a[i]=j;
                               count+=answer(a,n,i+1);
                   }
           }
       }
       return count;
}

int main()
{
    int t;
    char a[100];
    scanf("%d",&t);
    while(t--)
    {
              int n;
              scanf("%d",&n);             
              printf("%d\n",answer(a,n));
    }
    getchar();
    return 0;
}
