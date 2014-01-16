/*
	Name: Any Segment Intersect Brute Force
	Copyright: 
	Author: 
	Date: 30/07/13 18:50
	Description: Does any segment intersect bruteforce
	O(n^2)
*/



#include<iostream>
#include<utility>
#include<map>
#include<vector>
using namespace std;


//------------------------ Simple data types------------------------------------
typedef pair<int,int> point;
typedef pair<point,point> segment;


//----------------- Helper functions--------------------------
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


bool intersect(const segment &A,const segment &B)
{
	point a=A.first;
	point b=A.second;
	point c=B.first;
	point d=B.second;
	dir dir_abc=direction(a,b,c);
	dir dir_abd=direction(a,b,c);
	dir dir_cda=direction(a,b,c);
	dir dir_cdb=direction(a,b,c);
	
	if(dir_abc==collinear && on_segment(a,b,c))
		return true;
	else if(dir_abd==collinear && on_segment(a,b,d))
		return true;
	else if(dir_cda==collinear && on_segment(c,d,a))
		return true;
	else if(dir_cdb==collinear && on_segment(c,d,b))
		return true;
	else if(dir_abc+dir_abd==0&&dir_cda+dir_cdb==0) // this means either they are collinear or have opposite direction
		return true;
	else
		return false;
}

bool any_segment_intersects(const vector<segment> &segments)
{
	for(int i=0;i<segments.size()-1;i++)
	{
		for(int j=i+1;j<segments.size();j++)
		{
			if(intersect(segments[i],segments[j]))
				return true;
		}
	}
	return false;
}

//#define TEST_MODE
int main()
{
	#ifdef TEST_MODE
	freopen("segment_test.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		vector<segment> segments;
		int n;
		cin>>n;
		segments.resize(n);
	
		for(vector<segment>::iterator seg=segments.begin();seg!=segments.end();seg++)
		{
			cin>>(*seg).first.first;
			cin>>(*seg).first.second;
			cin>>(*seg).second.first;
			cin>>(*seg).second.second;
		}	
		
		cout<<any_segment_intersects(segments)<<endl;
	}
	
	
}
