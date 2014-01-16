#include<stdio.h>
#include<assert.h>

int main()
{
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int number=0;
              int flag=-1;
              char ch;
              int count=0;
              fflush(stdin);
              while(1)
              {
                     
                ch=getchar();
                if(ch=='0') count++; 
                else if(ch==' '||ch=='\n')
                {
                    // printf("got \"%c\" count=%d number =%d\n",ch,count,number); 
                     if(count==1) flag=0;
                     else if(count==2) flag=1; 
                     else
                     {
                         assert(flag==0||flag==1);
                         int add=flag?1:0;
                         while((count--)>2)
                                           number=number*2+add;
                     }
                     count=0;
                }
                if(ch=='\n') break;
              }
              printf("%d\n",number);
    }
    return 0;
}
