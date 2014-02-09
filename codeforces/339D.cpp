#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > tree(n+1,vector<int>(1<<n));	
	for(int i=0;i<(1<<n);i++)
		cin>>tree[n][i];
	
	bool Xor=false;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<(1<<i);j++)
		{
			if(Xor)
				tree[i][j]=	tree[i+1][j<<1]^tree[i+1][(j<<1)+1];
			else
				tree[i][j]=	tree[i+1][j<<1]|tree[i+1][(j<<1)+1];
		}
		Xor^=true;
	
	}
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		l--;
		int nDummy=n;
		tree[n][l]=r;
		nDummy--;
		l/=2;
		bool Xor=false;
		while(nDummy>=0)
		{
			if(Xor)
				tree[nDummy][l]=tree[nDummy+1][l*2]^tree[nDummy+1][l*2+1];
			else
				tree[nDummy][l]=tree[nDummy+1][l*2]|tree[nDummy+1][l*2+1];
			nDummy--;
			l/=2;
			Xor^=true;
			
		}
		cout<<tree[0][0]<<endl;
	}
}
