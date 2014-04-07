#include<iostream>
#include<vector>
using namespace std;

#define INVALID 1000000
int main()
{
	int x,k;
	vector<int> v;
	cin>>x>>k;
	v.resize(k);
	for(int i=0;i<k;i++)
		cin>>v[i];
		
	vector<vector<int> > minCount(k,vector<int>(x+1,INVALID));
	
	for(int i=0;v[k-1]*i<=x;i++)
		minCount[k-1][v[k-1]*i]=i;
	
	for(int i=k-1;i>0;i--)
		for(int j=x;j>=0;j--)
			if(minCount[i][j]!=INVALID)
			{
				for(int k=minCount[i][j];k*v[i-1]+j<=x;k++)
				{
					if(minCount[i-1][k*v[i-1]+j]!=INVALID) break;
					minCount[i-1][k*v[i-1]+j]=k;
				}
			}	
	
	cout<<((minCount[0][x]!=INVALID)?"YES":"NO");
}
