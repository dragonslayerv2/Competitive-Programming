#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    char n[200];
    scanf("%d",&t);
    while(t--)
    {
              scanf("%s",n);
              int flag=0;
              for(int i=strlen(n)-1;i>=0;i--)
              {
                      if(n[i]=='4')
                      {
                                   flag=1;
                                   n[i]='7';
                                   break;
                      }
                      else
                      {
                                   n[i]='4';
                      }
              }
              if(flag==0) putchar('4');
              printf("%s\n",n);
    }
    return 0;
}
