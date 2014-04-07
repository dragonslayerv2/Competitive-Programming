#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> f(40);
	vector<int> g(40);
	
	f[0]=1;
	
	for(int i=2;i<f.size();i++)
	{
		g[i]=f[i-2]+g[i-2];
		f[i]=f[i-2]+2*g[i];
	}
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==-1)
			break;
		else
			printf("%d\n",f[n]);
	}
}
