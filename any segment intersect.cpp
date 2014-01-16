/*
	Name: Does any segment intersect
	Copyright: 
	Author: Shobhit Saxena
	Date: 29/07/13 19:16
	Description: THis algorithm find whether any line segment intersect or not using sweep line algorithm.
				Overall complexity O(nlogn)
				uses RB tress but maps here do the same work.
*/


#include<iostream>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
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

//------------------------------------Main driver function-----------------------------
// this structure is needed during sorting...
	struct endpoint
	{
		int x, y;
		bool is_left;	
		int segment_number;
		endpoint(const point &P,int SEGMENT_NUMBER,bool IS_LEFT)
		{
			x=P.first;
			y=P.second;
			is_left=IS_LEFT;
			segment_number=SEGMENT_NUMBER; // well this i require to find the segment in  the tree
		}
	};

bool cmp_endpoints(const endpoint &a,const endpoint &b)
{
	if(a.x<b.x)
		return true;
	else if(a.is_left&&!b.is_left)
		return true;	
	else if(!a.is_left&&b.is_left)
		return false;
	else if(a.y<b.y)
		return true;
	else
		return false;
	
}

class is_below
{
	public:
		bool operator ()(const segment &segment1, const segment &segment2)
		{
			dir direct=direction(min(segment2.first,segment2.second), max(segment2.first,segment2.second), min(segment1.first,segment1.second));
			if(direct==clockwise)
				return true;
			else
				return false;
		}
};


ostream & operator <<(ostream &stream,const pair<int,int> &s)
{
	stream<<" ("<<s.first<<", ";
	stream<<s.second<<")";
	return stream;
}
bool any_segment_intersects(const vector<segment> &segments)
{
	vector<endpoint> endpoints;
	endpoints.reserve(2*segments.size());
	for(int i=0;i<segments.size();i++)
	{
		cout<<segments[i].first;
		cout<<segments[i].second<<endl;;
		endpoints.push_back(endpoint(min(segments[i].first,segments[i].second),i,true ));
		endpoints.push_back(endpoint(max(segments[i].first,segments[i].second),i,false));
	}
	
	sort(endpoints.begin(),endpoints.end(),cmp_endpoints);
	
	
	map<segment,bool,is_below> T;
	
	for(int i=0;i<endpoints.size();i++)
	{
		cout<<"Got ";
		cout<<endpoints[i].x<<" "<<endpoints[i].y<<endl;
		
		if(endpoints[i].is_left==true)
		{
			cout<<"Left endpoint of segment number ";
			cout<<endpoints[i].segment_number<<endl;
			cout<<"Inserting segment "<<segments[endpoints[i].segment_number].first<<segments[endpoints[i].segment_number].second<<endl;
			map<segment,bool>::iterator s=T.insert(make_pair(segments[endpoints[i].segment_number],true)).first;
			map<segment,bool>::iterator sf=s;
			sf++;
			map<segment,bool>::iterator sb=s;
			sb--;
			if(s!=T.begin())// this implies a segment below S exist
			{
				cout<<"Segment below S exist"<<endl;
				cout<<"Comparing with "<<(*sb).first.first<<" "<<(*sb).first.second<<endl;
				if(intersect((*sb).first,(*s).first))
				{
					cout<<"It intersect with "<<(*sb).first.first<<" "<<(*sb).first.second<<endl;
						return true;
				}
				
			}
			if(sf!=T.end())	// this imples a segment above S exist
			{
				cout<<"Segment above S exist"<<endl;
				cout<<"Comparing with "<<(*sf).first.first<<" "<<(*sf).first.second<<endl;
				if(intersect((*sf).first,(*s).first))
				{
					cout<<"It intersect with "<<(*sf).first.first<<" "<<(*sf).first.second<<endl;
					return true;
				}
					
			}
		}
		else
		{
			cout<<"Right endpoint of segment number ";
			cout<<endpoints[i].segment_number<<endl;
			cout<<"Searching for "<<segments[endpoints[i].segment_number].first<<" "<<segments[endpoints[i].segment_number].second<<endl;
			map<segment,bool>::iterator s=T.find(segments[endpoints[i].segment_number]);	
			if(s==T.end())
			{
				cout<<"Invalid Segment"<<endl<<endl;
				throw 1;
			}
			if(s!=T.begin()) // this imples a segment below s exist
			{
				cout<<"Segment below S exist";
				map<segment,bool>::iterator sf=s;
				map<segment,bool>::iterator sb=s;
				sf++;
				sb--;
				cout<<(*sb).first.first<<" "<<(*sb).first.second<<endl;
				if(sf!=T.end()) // this implies a segment above S exist
				{
					cout<<"Segment Above S exist";
					cout<<(*sf).first.first<<" "<<(*sf).first.second<<endl;
					if(intersect((*sf).first,(*sb).first))
					{
						cout<<"Both intersect"<<endl;
			//			return true;	
					}
						
				}	
			}
			cout<<"Removing "<<(*s).first.first<<" "<<(*s).first.second<<endl;
			T.erase(s);
		}
	}
	return false;
}

#define TEST_MODE
int main()
{
	#ifdef TEST_MODE
	freopen("segment_test.txt","r",stdin);
	#endif
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
		
	cout<<any_segment_intersects(segments);	
}
