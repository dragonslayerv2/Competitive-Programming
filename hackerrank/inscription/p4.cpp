#include<iostream>
#include<cmath>
using namespace std;

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define STACK_SIZE 6000010
#define MAX 6000010


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
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	
	cin>>points[0].x>>points[0].y;
	
    for(int i=1;i<n;i++){
    	long long oldX=points[i-1].x;
    	long long oldY=points[i-1].y;
    	
		points[i].x=(a*oldX*oldX+b*oldY*oldY+oldX/c+oldY/d)%10000;
		points[i].y=(b*oldX*oldX+a*oldY*oldY+oldX/d+oldY/c)%10000;
		
    }

//	for(int i=0;i<n;i++)
//		cout<<points[i].x<<" "<<points[i].y<<endl;      
    getminy(n);
    
    qsort ( points+1, n-1, sizeof(*points), comparepolar);  
   
    push(points[0]);
    push(points[1]);
    
    for(int i=2;i<n;i++)
    {
		while(ccw(stack[top-1],stack[top],points[i])<=0&&top>0)
   			top--;
		push(points[i]);
    }
    
	int t=top;
    double distance=0;
	
	long long x=(stack[t].x-stack[0].x);
    x*=x;
    long long y=(stack[t].y-stack[0].y);
    y*=y;
    distance+=pow((double)x+y,(double)0.5);
    
	while(t>=1)
    {
		long x=(stack[t].x-stack[t-1].x);
		x*=x;
		long y=(stack[t].y-stack[t-1].y);
    	y*=y;
    	distance+=pow((double)x+y,(double)0.5);
		t--;
    }
    cout.setf(ios::fixed);
    cout.precision(3);
    cout<<distance;
}
