/*
	Name: Sorting the points with their polar angles.
	Copyright: 
	Author: Shobhit Saxena
	Date: 27/07/13 17:15
	Description: In convex hull we didn't take care of having the points on same side of x axis bcoz there we choose the point with min y make all the other points being shifted to the coordinates above y.
				Refer to cormen question number 33.1-3
*/


#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;


typedef pair<int,int> point;

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
	vector<point> points;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		points.push_back(make_pair(x,y));
	}
	sort(points.begin(),points.end(),cmppolar(point(0,0)));
	for(int i=0;i<n;i++)
	{
		cout<<points[i].first<<", "<<points[i].second;
		cout<<endl;
	} 
}
