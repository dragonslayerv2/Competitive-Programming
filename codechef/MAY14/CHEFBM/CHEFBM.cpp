#include<stdio.h>
#include<set>
#include<vector>
#include<map>
using namespace std;

bool isValid(map<int,int> &increment,set<int> &affected,int max)
{
	bool valid=true;
	for(set<int>::iterator i=affected.begin();i!=affected.end();i++)
	{
		if(*i!=max&&increment[*i]>increment[*i+1]+1)
			return false;				
		if(*i!=1&&increment[*i-1]>increment[*i]+1)
			return false;		
	}
	return true;
}
int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	vector<map<int,int> > increments(n+1);
	vector<set<int> > affected(n+1);
	while(k--)
	{
		int i,j;
		scanf("%d %d",&i,&j);
		increments[i][j]++;
		affected[i].insert(j);
	}
	for(int i=1;i<=n;i++)
	{
		if(!isValid(increments[i],affected[i],m))
			printf("-1");
		else
			printf("%d",m-1+(increments[i][m]-increments[i][1]));
		printf("\n");
	}
}
