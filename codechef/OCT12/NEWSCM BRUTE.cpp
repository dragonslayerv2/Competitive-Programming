#include<stdio.h>
#include<string.h>
#include<math.h>


inline int check(char a[],int n)
{
       if(a[0]==a[n-1])
                       return 0;
       else
           for(int i=0;i<n-1;i++)
           {
                            if(a[i]==a[i+1]) return 0;
           }
       return 1;
}

int main()
{
    char a[1000000];
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int n;
              scanf("%d",&n);
              int p=pow(4,n);
              int count=0;
              for(int i=0;i<p;i++)
              {
                      int x=i;
                      for(int j=0;j<n;j++)
                      {
                              a[j]=x%4;
                              x/=4;
                      }
                      a[n]=NULL;
                      if(check(a,n)) count++;
              }
              printf("%d\n",count);
    }
    getchar();
}
