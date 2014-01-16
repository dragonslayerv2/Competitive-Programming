/*
  Name: Minimum Length Triangulisation
  Copyright: 
  Author: Shobhit Saxena
  Date: 12/12/12 21:20
  Description: A triangulation of a polygon is a set of non-intersecting diagonals which partiions the polygon into diagonals.
               The length of a triangulation is the sum of the diagonal lengths.
               We seek to find the minimum length triangulation.
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//------------------------------------------------------------------------------
typedef struct
{
        int x;
        int y;
}point;

//------------------------------------------------------------------------------

point points[MAX];
int n;

int comparepolar (const void * a, const void * b)
{
    point p1=*(point*)a;
    point p2=*(point*)b;
    point p0=points[0];
    int dif=(p1.x*p2.y-p2.x*p1.y +p0.y*(p2.x-p1.x)+p0.x*(p1.y-p2.y));
    if((p1.y-p0.y)*(p2.y-p0.y)<0) return dif;
    else                          return (-1)*dif;

}

inline int sort()
{
    qsort ( points+1, n-1, sizeof(*points), comparepolar);      
}

inline void getpoint(point *x)
{
    scanf("%d",&(x->x));
    scanf("%d",&(x->y));
}

inline void putpoint(point x)
{
    printf("(%d,%d)\n",x.x,x.y);

}



int main()
{         
          for(n=0;n<6;n++)
          {
                           getpoint(&points[n]);
          }
          sort();
          for(int i=0;i<n;i++)
          {
                              putpoint(points[i]);                 
          }    
          
          fflush(stdin);
          getchar();
          return 0;    
}



