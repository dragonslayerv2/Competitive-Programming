#include<iostream>
#include<map>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	map<int,int> hor,ver;
	
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		hor[x]++;
		ver[y]++;
	}
	cout<<min(hor.size(),ver.size());
}

