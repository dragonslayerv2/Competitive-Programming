/*
	Name: To find whether there exist any collinear points triple in a set of points
	Copyright: 
	Author: Shobhit Saxena
	Date: 27/07/13 17:32
	Description: This algorithm finds whether there are any collinear points in a set of points.
	Overall complexity O(n^2 logn + n^2)
*/


#include<iostream>
#include<assert.h>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> point;

bool collinear(const point&a, const point&b, const point&c)
{
	int dir =(b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second);
	return !dir;
}

class cmppolar
{
		point ref; // reference point
		
		bool above_x(const point& a)
		{
			if(a.first>=0) // on the x axis is taken care by the cross product
				return true;
			else
				return false;
		}
	public:
		cmppolar()
		{
			ref=make_pair(0,0);
		}
		cmppolar(const point &REF)
		{
			ref=REF;
		}
		
		bool operator () (const point &a,const point&b)
		{
			point shifted_a=make_pair(a.first-ref.first,a.second-ref.second);
			point shifted_b=make_pair(b.first-ref.first,b.second-ref.second);
			
			if(!(above_x(a)^above_x(b))) // if both are same
			{
				int dir=(shifted_a.first-ref.first)*(shifted_b.second-ref.second)-(shifted_b.first-ref.first)*(shifted_a.second-ref.second);		
				if(dir<0)
					return true;
				else
					return false;		
			}
			else if(above_x(a))
				return true;
			else
				return false;
		}
};

int main()
{
	int n;
	cin>>n;
	assert(n>=3);
	vector<point> points;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		points.push_back(make_pair(x,y));
	}
	bool ispresent=false;
	for(int i=0;i<n-2;i++)
	{
		vector<point> temp_points;
		for(int j=i+1;j<n;j++)
		{
			temp_points.push_back(points[j]);
		}
		sort(temp_points.begin(),temp_points.end(),cmppolar(points[i]));
		
		for(int j=0;j<temp_points.size()-1;j++)
		{
			if(collinear(points[i],temp_points[j],temp_points[j+1]))
			{
				ispresent=true;
				break;  // um... set union data structure here will help u to find all the points collinear..
			} // do here whateve u want
		}
	}
	cout<<ispresent;
	return 0;
}
