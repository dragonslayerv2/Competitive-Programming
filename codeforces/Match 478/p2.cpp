#include<iostream>
using namespace std;

int main(){
	long long n,m;
	cin>>n>>m;
	long long max=((n-m)*(n-m+1))/2;
	long long min1=(n/m);
	min1*=(n/m-1);
	min1/=2;
	min1*=(m-n%m);
	long long min2=(n/m+1);
	min2*=(n/m);
	min2/=2;
	min2*=n%m;
	long long min=min1+min2;
	
	
	cout<<min<<" "<<max;
	
}
