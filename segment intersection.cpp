/*
	Name: Check whether two line segments intersect or not
	Copyright: 
	Author: Shobhit Saxena
	Date: 27/07/13 15:08
	Description: Refer to cormen page nnumber 1018
*/

#include<iostream>
using namespace std;

typedef pair<int,int> point;

enum dir
{
	clockwise=-1,collinear,anticlockwise
};

dir direction(const point&a, const point&b, const point&c)
{
	int dir =(b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second);
	if(dir==0)
		return collinear;
	else if(dir>0)
		return anticlockwise;
	else 
		return clockwise;
}

bool on_segment(const point&a, const point&b, const point&c)
{
	if(c.first>=min(a.first,b.first)&&c.second<=max(a.first,b.first)&&c.second>=min(a.second,b.second)&&c.second<=max(a.second,b.second))
		return true;
	else
		return false;
}


bool intersect(const point&a, const point&b, const point&c, const point&d)
{
	dir dir_abc=direction(a,b,c);
	dir dir_abd=direction(a,b,c);
	dir dir_cda=direction(a,b,c);
	dir dir_cdb=direction(a,b,c);
	
	if(dir_abc==0 && on_segment(a,b,c))
		return true;
	else if(dir_abd==0 && on_segment(a,b,d))
		return true;
	else if(dir_cda==0 && on_segment(c,d,a))
		return true;
	else if(dir_cdb==0 && on_segment(c,d,b))
		return true;
	else if(dir_abc+dir_abd==0&&dir_cda+dir_cdb==0) // this means either they are collinear or have opposite direction
		return true;
	else
		return false;
}

int main()
{
	point a1,a2;	// for line segment 1
	point b1,b2;	// for line segment 2
	
	
	cin>>a1.first>>a1.second;
	cin>>a2.first>>a2.second;
	cin>>b1.first>>b1.second;
	cin>>b2.first>>b2.second;
		
	cout<<boolalpha<<intersect(a1,a2,b1,b2);
}
