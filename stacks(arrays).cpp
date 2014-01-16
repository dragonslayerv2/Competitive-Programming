/*
  Name: Arrayed stack
  Copyright: 
  Author: 
  Date: 08/11/12 10:51
  Description: 
*/

#include<stdio.h>

#define MYNULL -1
#define STACK_SIZE 10

inline void push(int stack[],int *top,int n)
{
    stack[++(*top)]=n;
}

inline int pop(int stack[],int *top)
{
       if(*top<0) return MYNULL;
       return stack[(*top)--];
}

void print(int stack[],int *top)
{
     if(*top<0) return;
     int n=pop(stack,top);
     printf("%d ",n);
     print(stack,top);
     push(stack,top,n);
}



int main()
{
    int stack[STACK_SIZE];
    int top=-1;
    
    push(stack,&top,1);
    push(stack,&top,2);
    push(stack,&top,3);
    push(stack,&top,4);
    push(stack,&top,5);
    push(stack,&top,6);
    
    print(stack,&top);
    
    print(stack,&top);
    getchar();
}
