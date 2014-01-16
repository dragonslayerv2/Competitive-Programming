#include<iostream>
#include<climits>
using namespace std;

typedef pair<int,int> point;

int getarea(point &a,point &b,point &c)
{
	int area=a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second);
	return area>0?area:(-1)*area;
}

int main()
{
	int n;
	cin>>n;
	int max=INT_MIN;
	int maxpos=-1;
	int min=INT_MAX;
	int minpos=-1;
	
	for(int i=1;i<=n;i++)
	{
		point a,b,c;
		cin>>a.first>>a.second;
		cin>>b.first>>b.second;
		cin>>c.first>>c.second;
		
		int area=getarea(a,b,c);
		if(area<=min)
		{
			min=area;
			minpos=i;
		}
		if(area>=max)
		{
			max=area;
			maxpos=i;
		}
	}
	cout<<minpos<<" "<<maxpos;
	return 0;
}
