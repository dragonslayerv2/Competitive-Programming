#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int x,k;
vector<int> v;

map<int,int> hashvalues[5][150000];

bool solve(int x,int pos,int c)
{
	if(x==0&&pos==k)
		return true;
	if(x<0)
		return false;
	if(pos>=k)
		return false;
	if(x-v[pos]*c<0)
		return false;
	
	if(hashvalues[pos][x].find(c)==hashvalues[pos][x].end())
	{
		hashvalues[pos][x][c]=(solve(x-c*v[pos],pos+1,c)||solve(x,pos,c+1));
	}
	return hashvalues[pos][x][c];
}
int main()
{
	cin>>x>>k;
	v.resize(k);
	for(int i=0;i<k;i++)
		cin>>v[i];
	reverse(v.begin(),v.end());
	
	cout<<(solve(x,0,0)?"YES":"NO");
}
