#include<stdio.h>
#include<ctype.h>
#define MAX 100001
int main()
{
    int t;
    scanf("%d",&t);
    char string[MAX];
    while(t--)
    {
              int flag=0;
              int c=0,s=0;
              int ct=0,st=0;
              char x;
              int n;
              scanf("%d",&n);
              fflush(stdin);
                      
              for(int i=0;i<n;i++)
              {
                      
                      x=getchar();
                      if(toupper(x)=='S')
                                     {flag=1;   s++;}
                      else if(toupper(x)=='C')
                                      {flag=1;       c++;}
                      
                      if(s==4)
                      {
                              flag=0;
                              s=c=0;
                              st++;
                      }
                      else if(c==4)
                      {
                              flag=0;
                              s=c=0;
                              ct++;
                      }
              }
              printf("%d-%d",st,ct);
              if(flag) printf(",%d-%d",s==0?0:s==1?15:s==2?30:40,c==0?0:c==1?15:c==2?30:40);
              printf("\n");
              
              
    }
    return 0;
}
