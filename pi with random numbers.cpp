#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;


typedef pair<long long ,long long> point;

bool inside_circle(point x,long long r)
{
	return ((x.first*x.first+x.second*x.second)<=r*r);
}

point getrandompoint()
{
	int point1=999*rand()%200001;
	point1=point1-100000;
	
	int point2=999*rand()%200001;
	point2=point2-100000;
	
	return make_pair(point1,point2);
}


int main()
{
	srand(time(NULL));
	int count=0;
	int total=1000000;
	for(int i=0;i<total;i++)
	{
		count+=inside_circle(getrandompoint(),100000);
	}
	
	cout<<(double)((count*4))/total;
}
