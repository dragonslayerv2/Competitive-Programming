#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

int abs(int a)
{
	if(a<0)
		return -1*a;
	else
		return a;
}
vector<vector<long long> > hashmap;

long long solve(int aPos,int bPos,string &a,string &b,int spaceWeight)
{
	if(aPos==a.size())
		return (b.size()-bPos)*spaceWeight;
	else if(bPos==b.size())
		return (a.size()-aPos)*spaceWeight;
	else if(hashmap[aPos][bPos]==-1)
	{
		long long noSpaceAdded=abs(a[aPos]-b[bPos])+solve(aPos+1,bPos+1,a,b,spaceWeight);
		long long aSpaceAdded =spaceWeight+solve(aPos+1,bPos,a,b,spaceWeight);
		long long bSpaceAdded =spaceWeight+solve(aPos,bPos+1,a,b,spaceWeight);
		hashmap[aPos][bPos]=min(noSpaceAdded,min(aSpaceAdded,bSpaceAdded));
	}
	return hashmap[aPos][bPos];
	
}

int main()
{
	char A[5000];
	char B[5000];
	scanf("%s%s",A,B);
	string a,b;
	a=A;
	b=B;
	
	hashmap.resize(a.size(),vector<long long>(b.size(),-1));
	int spaceWeight;
	scanf("%d",&spaceWeight);
	printf("%lld",solve(0,0,a,b,spaceWeight));
}
