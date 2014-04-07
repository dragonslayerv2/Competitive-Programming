#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define PI 3.14159265359

struct circle
{
	long long x,y,r;
	
	bool operator <(const circle &c2)const
	{
		return r<c2.r;
	}
};

bool intersects(circle C1,circle C2)
{
	return ((C1.x-C2.x)*(C1.x-C2.x)+(C1.y-C2.y)*(C1.y-C2.y))<=max(C1.r,C2.r)*max(C1.r,C2.r);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<circle> C(n);
		for(int i=0;i<n;i++)
			cin>>C[i].x>>C[i].y>>C[i].r;
		
		sort(C.rbegin(),C.rend());
		
		double area=0;
		for(int i=0;i<n;i++)
		{
			int iCount=0;
			for(int j=0;j<i;j++)
			{
				if(intersects(C[i],C[j]))
					iCount++;
			}
			if(iCount%2==0)
				area+=PI*C[i].r*C[i].r;
			else
				area-=PI*C[i].r*C[i].r;
		}
		cout.setf(ios::fixed);
		cout.precision(6);
		cout<<area<<endl;
	}
}


