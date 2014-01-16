#include<stdio.h>

int main()
{
   
    int t;
    scanf("%d ",&t);
    while(t--)
    {
              char a;
              long long length=0;
              long long total;
              long long count=0;
              long long minus=0;
              int ans;
              while(1)
              {
                a=getchar();
                length++;
                if(a=='7') count++;
                
             //   printf("got %c count=%lld\n",a,count);
                else
                {
                     minus+=(count*(count+1)/2);
                     count=0;
                     if(a=='\n') break;
                     
                }
              }
              length--;
              
         //     printf("length=%lld minus=%lld\n",length,minus);
              printf("%lld\n",(length*(length+1))/2 - minus);         
    }
}
