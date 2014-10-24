#include <iostream>
#include <stack>
#include <stdlib.h>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

struct Point
{
    double x;
    double y;
};
Point p0;
Point coordinates[3000005];
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
double dist(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
double orientation(Point p, Point q, Point r)
{
    double val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  
    return (val > 0)? 1: 2; 
}

int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
   double o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}
double convexHull(Point points[], double n)
{
	vector<Point> hullPoints;
   double ymin = points[0].y;
   int min = 0;
   for (int i = 1; i < n; i++)
   {
     double y = points[i].y;
     if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
   swap(points[0], points[min]);
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
   for (int i = 3; i < n; i++)
   {
      while (S.size()>=2&&orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
   while (!S.empty())
   {
       Point p = S.top();
       hullPoints.push_back(p);
       S.pop();
   }
   int i;
   double perimeter=0;
   for(i=1;i<hullPoints.size();i++){
   		perimeter+=sqrt((hullPoints[i].x- hullPoints[i-1].x)*(hullPoints[i].x- hullPoints[i-1].x) + 
   					(hullPoints[i].y- hullPoints[i-1].y)*(hullPoints[i].y- hullPoints[i-1].y));
   }
   perimeter+=sqrt((hullPoints[0].x- hullPoints[i-1].x)*(hullPoints[0].x- hullPoints[i-1].x) + 
   					(hullPoints[0].y- hullPoints[i-1].y)*(hullPoints[0].y- hullPoints[i-1].y));
   
   return perimeter;
}
int main()
{
		freopen("in.txt","r",stdin);
	int N;
	cin>>N;
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	
	Point start;
	cin>>start.x>>start.y;
	
	
	coordinates[0]=start;
	
	for(int i=1;i<N;i++){
		Point temp;
		int xcoordinate=coordinates[i-1].x;
		int ycoordinate=coordinates[i-1].y;
		temp.x= ( (a * xcoordinate* xcoordinate)%10000  + (b * ycoordinate * ycoordinate)%10000 + (xcoordinate / c)%10000 + (ycoordinate / d)%10000 ) % 10000 ;
		temp.y= ( (b * xcoordinate* xcoordinate)%10000  + (a * ycoordinate * ycoordinate)%10000 + (xcoordinate / d)%10000 + (ycoordinate / c)%10000 ) % 10000 ;
	
		coordinates[i]=temp; 
	}
		
    printf("%.3f\n",convexHull(coordinates, N));
   
}
