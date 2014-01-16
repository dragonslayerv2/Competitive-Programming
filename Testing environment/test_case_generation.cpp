// Any segment intersect Test case generation

#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

#define TOTAL_CASES 100
#define PER_CASE_SIZE 20
#define POINT_RANGE 100
int main()
{
	srand(time(NULL));
	cout<<TOTAL_CASES<<endl;
	for(int i=0;i<TOTAL_CASES;i++)
	{
		cout<<PER_CASE_SIZE<<endl;
		for(int j=0;j<PER_CASE_SIZE;j++)
		{
			pair<int,int> a;
			pair<int,int> b;
			a.first=rand()%POINT_RANGE;
			a.second=rand()%POINT_RANGE;
			b.first=rand()%POINT_RANGE;
			b.second=rand()%POINT_RANGE;
			while(a.first==b.first)
			{
				a.first=rand()%POINT_RANGE;
			}
			while(a>=b)
			{
				a.first=rand()%POINT_RANGE;
				a.second=rand()%POINT_RANGE;
			}
			cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second;
			cout<<endl;
		}
		cout<<endl;
	}
	
}
