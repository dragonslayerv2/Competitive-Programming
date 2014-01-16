#include<iostream>
using namespace std;

typedef pair<int,int> point;
long long dist(point &a,point &b)
{
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int main()
{
	int n;

	cin>>n;
	int count=0;
	while(n--)
	{
		point a;
		point b;
		point c;
		cin>>a.first>>a.second;
		cin>>b.first>>b.second;
		cin>>c.first>>c.second;
		
		long long distab=dist(a,b);
		long long distbc=dist(b,c);
		long long distca=dist(c,a);
		if(distab+distbc==distca)
			count++;
		else if(distca+distbc==distab)
			count++;
		else if(distab+distca==distbc)
			count++;
	}
	cout<<count<<endl;
}
