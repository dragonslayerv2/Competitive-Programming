#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 4

int W[MAX][MAX]={{0,1,2,0},{-1,0,0,1},{-1,-1,0,-1},{1,1,1,0}};

vector<int> dijikstras(int G[][MAX],int S)
{
	priority_queue<pair<int,int> > pQ;
	//--------------------- initialisation -------------------------------------
	pQ.push(make_pair(0,S));
	for(int i=0;i<MAX;i++)
	{
		if(i!=S)
		{
			pQ.push(make_pair(numeric_limits<int>::min(),i));
		}
	}
	//--------------------------------------------------------------------------
	
	
	 
}


int main()
{
	

}

