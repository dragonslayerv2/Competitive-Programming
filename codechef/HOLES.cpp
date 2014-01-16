#include<stdio.h>

int main()
{
    int t,count;
    char c,i;
    scanf("%d",&t);
    while(t--)
    {
              count=0;
              fflush(stdin);
              i=0;
              do
              {
                  i++;
               c=getchar()_unlocked();
               switch(c)
               {
                        case 'A':
                        case 'D':
                        case 'O':
                        case 'P':
                        case 'Q':
                        case 'R':count++;
                                 break;
                        case 'B': count+=2;
                        break;
               } 
               
              }while(c!='\n');
              if(i==1)
              {
              t++;continue;
              }
              printf("%d\n",count);
              
    }
    return 0;
}
