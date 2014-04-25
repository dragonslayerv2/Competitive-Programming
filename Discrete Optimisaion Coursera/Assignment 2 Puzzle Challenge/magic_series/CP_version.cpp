#include<iostream>
#include<cstdio>
#include<list>
#include<stack>
#include<vector>
using namespace std;

const int INVALID=-1;

struct propogationEvent
{
	int id;
	char type;
	int target;
	
	propogationEvent(int I=-1,char T='I',int TAR=-1):id(I),type(T),target(TAR){}
};

vector<int> series;
vector<vector<bool> > domain;
stack<propogationEvent> propogationStack;

int main(int argc,char *argv[])
{
	if(argc>=1)
	{
			int n;
			sscanf(argv[1],"%d",&n);		
			
			domain.resize(n,vector<int>(n,true));
			series.resize(n,-1);
			
			for(int i=1;i<n;i++)				
				for(int j=n/i+1;j<n;j++)
					domain[i][j]=true;		
	}
	else
		cout<<"Usage: "<<argv[0]<<" [size_of_series]"<<endl;s
}
