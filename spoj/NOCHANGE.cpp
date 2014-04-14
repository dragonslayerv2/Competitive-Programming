#include<iostream>
#include<map>
#include<vector>
using namespace std;

int x,k;
vector<int> v;

map<pair<int,int>,int> hashvalues[5];

bool solve(int x,int pos,int lastCount)
{
	if(x==0)
		return true;
	else if(x<0)
		return false;
	else if(pos==k)
		return false;
	
	if(hashvalues[pos].find(make_pair(x,lastCount))==hashvalues[pos].end())
	{
		for(int i=1;i<=lastCount&&v[pos]*i<=x;i++)
		if(solve(x-v[pos]*i,pos+1,i)==true)
		{
			hashvalues[pos][make_pair(x,lastCount)]=true;
			break;			
		}
	}
	return hashvalues[pos][make_pair(x,lastCount)];
}
int main()
{
	
	cin>>x>>k;
	v.resize(k);
	for(int i=0;i<k;i++)
		cin>>v[i];
	
	cout<<(solve(x,0,INT_MAX)?"YES":"NO");
}
