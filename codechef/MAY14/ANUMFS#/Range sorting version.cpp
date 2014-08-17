#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<map>
#include<climits>
using namespace std;

#define MAX 2030

int G[MAX][MAX] = {0};
int B[MAX][MAX] = {};

set<pair<int,int> > points;

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

bool sendPlane(int id, int x, int y) {
	printf("%d %d %d\n", id, x, y);
	fflush(stdout);
	char temp[4];
	scanf("%s", temp);
	return temp[0]=='y';
}

struct plane
{
	int r,c,id;
	bool operator <(const plane &p2) const
	{
		return double(r)/c <double(p2.r)/c;
	}
};


int main()
{
	getGrid();	
	int n;
	scanf("%d",&n);
	vector<plane> planes(n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&planes[i].r,&planes[i].c);
		planes[i].id=i;
	}
	
	sort(planes.rbegin(),planes.rend());
	#ifdef DEBUG
	for(int i=0;i<planes.size();i++)
		cout<<planes[i].r<<planes[i].c<<endl;
	#endif
	
	int planeToUse=0;
	pair<int,int> lastFront;
	vector<pair<int,int> > removed;
	while(points.size()&&planeToUse<planes.size())
	{
		if(!removed.size())
			removed.clear();
		lastFront=*(points.begin());
		bool reply=sendPlane(planes[planeToUse].id,lastFront.first,lastFront.second);
		if(reply)
		{
			for(set<pair<int,int> >::iterator i=points.begin();i!=points.end();i++)
				if(dist(lastFront,*i)>planes[planeToUse].r)
				{
					#ifdef DEBUG
						cout<<"Removing "<<i->first<<i->second<<endl;
					#endif
					removed.push_back(*i);
				}
			for(vector<pair<int,int> >::iterator i=removed.begin();i!=removed.end();i++)
				points.erase(*i);
		}
		else
		{
			for(set<pair<int,int> >::iterator i=points.begin();i!=points.end();i++)
				if(dist(lastFront,*i)<=planes[planeToUse].r)
				{
					#ifdef DEBUG
						cout<<"Removing "<<i->first<<i->second<<endl;
						cout<<"Plane Distance is "<<planes[planeToUse].r<<endl;
					#endif
					removed.push_back(*i);
				}
			
			for(vector<pair<int,int> >::iterator i=removed.begin();i!=removed.end();i++)
				points.erase(*i);
		}
		
		if(!points.size())
			planeToUse++;
			
		else if(lastFront==*(points.begin()))
		{
			planeToUse++;
			while(planeToUse<planes.size()&&planes[planeToUse].r>=planes[planeToUse-1].r)
				planeToUse++;
		}
	}	
	if(points.size()==0)
		printf("-1 -1 -1\n");
	else
		printf("-1 %d %d\n",points.begin()->first,points.begin()->second);
	fflush(stdout);
}
