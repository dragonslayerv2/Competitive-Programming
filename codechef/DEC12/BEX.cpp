#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
typedef struct item
{
        char name[20];
        int position;
        int min;
}item;

item stack[1000000];

int top=0;

int main()
{
    int t;
    scanf("%d",&t);
    int min=INT_MAX;
    int counter=0;
    while(t--)
    {
            //  printf("min=%d\n",min);
              int n;
             // fflush(stdin);
              scanf("%d",&n);
              
              if(n==-1)
              {
                       if(top==0) continue;
                       top--;
                       printf("%d %s\n",counter-stack[top].position,stack[top].name);
                       counter=stack[top].position-1;
                       if(top==0) min=INT_MAX;
                       else min=stack[top-1].min;           
              }
              else
              {
                  counter++;
                  char temp[20];
                  
                  if(n<=min&&n!=0)
                  {          
                            scanf(" %s",stack[top].name);
                            stack[top].position=counter;
                            stack[top].min=n;
                            min=n;
                            top++;
                  }
                  else scanf(" %s",temp);
                  if(n==0) counter--;
                  
              }
              //printf("counter=%d\n",counter);
    }
    return 0;
}
