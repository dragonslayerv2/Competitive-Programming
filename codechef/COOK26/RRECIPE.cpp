#include<stdio.h>
#include<string.h>

#define MOD 10000009
int main()
{
    int t;
    int i;
    char a[1000000];
    scanf("%d",&t);
    while(t--)
    {
              scanf("%s",a);
              int len=strlen(a);
              int end=len/2;
              int count=1;
              
              for(i=0;i<end;i++)
              {
                                if(a[i]=='?')
                                {
                                             if(a[len-i-1]=='?')
                                             {
                                                                count*=26;
                                                                count=count%MOD;
                                             }                     
                                }                   

                                else if(a[i]!=a[len-i-1]&&a[len-i-1]!='?')
                                {
                                          count=0;break;          
                                }
              }
              if(len%2!=0&&a[len/2]=='?')
              {
                          
                          count=count*26;
                          count%=MOD;
              }
              printf("%d\n",count);
              
    }
    
    return 0;
}
