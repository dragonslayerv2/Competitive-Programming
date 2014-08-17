#include<iostream>
#include<time.h>
#include<cstdlib>
#include<limits>
#include<set>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<map>
#include<climits>
using namespace std;

#define MAX 2030

struct plane
{
	int r,c,id;
	bool operator <(const plane &p2) const
	{
		return double(r)/c <double(p2.r)/c;
	}
};

int G[MAX][MAX] = {0};
int B[MAX][MAX] = {};
set<pair<int,int> > points;
vector<plane> planes;

inline int dist(pair<int,int> p1,pair<int,int> p2)
{
	return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}

void getGrid()
{
	vector<pair<int, int> > C;
	int n;
	scanf("%d", &n);
	int minx = INT_MAX, maxx = INT_MIN;
	int miny = INT_MAX, maxy = INT_MIN;
	
	while (n--) 
	{
		int x, y;
		scanf("%d%d", &x, &y);
		C.push_back(make_pair(x, y));
		minx = min(minx, x);
		miny = min(miny, y);
		maxx = max(maxx, x);
		maxy = max(maxy, y);
	}
	
	for (int i = 0; i < C.size(); i++) {
		int x = C[i].first + (-minx);
		int y = C[i].second + (-miny);
		G[y][x] = 1;
	}
	
	int mnx = minx, mny = miny;
	maxx = maxx - minx;
	minx = 0;
	maxy = maxy - miny;
	miny = 0;

	for (int i = miny; i <= maxy; i++) {
		int  flag = 0;
		for (int j = minx; j <= maxx; j++) { 
			if (G[i][j])
				flag = 1;
			B[i][j] += flag; 
		}
	}

	for (int i = miny; i <= maxy; i++) {
		int  flag = 0;
		for (int j = maxx; j >= minx; j--) { 
			if (G[i][j])
				flag = 1;
			B[i][j] += flag; 
		}
	}

	for (int j = minx; j <= maxx; j++) {
		int  flag = 0;
		for (int i = maxy; i >= miny; i--) { 
			if (G[i][j])
				flag = 1;
			B[i][j] += flag; 
		}
	}

	for (int j = minx; j <= maxx; j++) {
		int  flag = 0;
		for (int i = miny; i <= maxy; i++) { 
			if (G[i][j])
				flag = 1;
			B[i][j] += flag; 
		}
	}

	for (int j = minx; j <= maxx; j++) {
		for (int i = miny; i <= maxy; i++) {
			if (B[i][j] == 4)
				G[i][j] = G[i][j] || 1;
		}
	}
	
	for (int i = maxy; i >= miny; i--) 
		for (int j = minx; j <= maxx; j++) 
			if (G[i][j]) 
				points.insert(make_pair(mnx+j,mny+i));
}

bool sendPlane(int id, int x, int y) 
{
	printf("%d %d %d\n", id, x, y);
	fflush(stdout);
	char temp[4];
	scanf("%s", temp);
	return temp[0]=='y';
}


vector<pair<int,int> > removed;

void removeAreaInRegion(pair<int,int> point,int range)
{
	if(!removed.size())
		removed.clear();

	for(set<pair<int,int> >::iterator i=points.begin();i!=points.end();i++)
		if(dist(point,*i)<=range)
			removed.push_back(*i);
			
	for(vector<pair<int,int> >::iterator i=removed.begin();i!=removed.end();i++)
		points.erase(*i);
}

int countInRegion(pair<int,int> point,int range)
{
	int count=0;
	for(set<pair<int,int> >::iterator i=points.begin();i!=points.end();i++)
		if(dist(point,*i)<=range)
			count++;
	return count;
}

void removeAreaOutofRegion(pair<int,int> point,int range)
{
	if(!removed.size())
		removed.clear();

	for(set<pair<int,int> >::iterator i=points.begin();i!=points.end();i++)
		if(dist(point,*i)>range)
			removed.push_back(*i);

	for(vector<pair<int,int> >::iterator i=removed.begin();i!=removed.end();i++)
		points.erase(*i);	
}

int countOutRegion(pair<int,int> point,int range)
{
	int count=0;
	for(set<pair<int,int> >::iterator i=points.begin();i!=points.end();i++)
		if(dist(point,*i)>range)
			count++;
	return count;
}


void getPlanes()
{
	int n;
	scanf("%d",&n);
	planes.resize(n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&planes[i].r,&planes[i].c);
		planes[i].id=i;
	}	
}

void foundAt(int x,int y)
{
	printf("-1 %d %d\n",x,y);
	fflush(stdout);
}

vector<bool> canUse;

int getRandomPlaneId()
{
	int id=rand()%planes.size();
	while(!canUse[id])
		id=rand()%planes.size();
	return id;
}

int getOptimalPlaneId()
{
	return getRandomPlaneId();
}

int main()
{
	srand(time(NULL));
	getGrid();	
	getPlanes();
	
	bool found=false;
	
	canUse.resize(planes.size(),true);
	
	while(!found&&points.size())
	{
		int id=getOptimalPlaneId();
		bool reply=sendPlane(id,points.begin()->first,points.begin()->second);

		if(reply)
		{
			int lastSize=points.size();
			removeAreaOutofRegion(*points.begin(),planes[id].r);
			canUse[id]=false;
			if(points.size()==1)
			{
				found=true;
				break;
			}
		}
		else
		{
			removeAreaInRegion(*points.begin(),planes[id].r);
			if(points.size()==0)
				break;
		}
	}
	
	if(found)
		foundAt(points.begin()->first,points.begin()->second);
	else
		foundAt(-1,-1);		
}

