#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,m,a;
	cin>>n>>m>>a;
	cout<<ceil(float(n)/a)*ceil(float(m)/a);
	return 0;
}
