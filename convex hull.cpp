/*
  Name: Convex HUll Problem(Grahm's Scan Algo)
  Copyright: 
  Author: Shobhit Saxena
  Date: 25/10/12 20:55
  
  Description: Do care the way getminy is developed a special case is added to it.
  In the comparepolar function we are dealing with cot(x) not tan(x) refer to the graph.
  
  Finding the point wid min y help us to deal with the problem of periodicity in tignometric functions
  
  Area of triangle is simply the cross product of the two vectors. Hence its sign give us the direction in which we have moved.
               
*/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define STACK_SIZE 1000
#define MAX 1000


//------------------------------------------------------------------------------
struct point
{
       int x;
       int y;
} points[MAX],stack[STACK_SIZE];
int top=-1;
//-----------------------------------------------------------------------------
int comparepolar (const void * a, const void * b)
{
    point p1=*(point*)a;
    point p2=*(point*)b;
    point p0=points[0];
    int dif=(p1.x*p2.y-p2.x*p1.y +p0.y*(p2.x-p1.x)+p0.x*(p1.y-p2.y));
    if((p1.y-p0.y)*(p2.y-p0.y)<0) return dif;
    else                          return (-1)*dif;

}
//------------------------------------------------------------------------------
void getminy(int n)
{
    int minpos=0;
    for(int i=1;i<n;i++)
    {
     if(points[i].y<points[minpos].y||(points[i].y==points[minpos].y&&points[i].x>points[minpos].x))
           minpos=i;
     
    }
    point temp;
    temp=points[0];
    points[0]=points[minpos];
    points[minpos]=temp;
}


//------------------------------------------------------------------------------

inline void getpoint(point *x)
{
    scanf("%d",&(x->x));
    scanf("%d",&(x->y));
}

inline void putpoint(point x)
{
       printf("(%d,%d)",x.x,x.y);
}

inline int ccw(point a,point b,point c) 
{
       int area= (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
       if(area==0)     return 0;       
       else if(area<0) return -1;
       else            return 1;// Counter clockwise
}
//------------------------------------------------------------------------------

inline void push(point x)
{
       assert(top+1<STACK_SIZE);
       stack[++top]=x;
       
       
}
int main()
{  
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            getpoint(points+i);
    }
      
    getminy(n);
    
    qsort ( points+1, n-1, sizeof(*points), comparepolar);  
   
   
    push(points[0]);
    push(points[1]);
    
    for(int i=2;i<n;i++)
    {
            while(ccw(stack[top-1],stack[top],points[i])<=0&&top>0)
            {                          
           //   printf("stack-->");putpoint(stack[top]);printf("\n");
                                                              top--;
            }
            //printf("stack<--");putpoint(points[i]);printf("\n");
            push(points[i]);
    }
    int t=top;
    while(t>=0)
    {
              putpoint(stack[t]);
              printf("\n");
              t--;
    }
    fflush(stdin);
    getchar();   
}
