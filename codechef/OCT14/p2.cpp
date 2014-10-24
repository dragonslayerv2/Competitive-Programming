#include<iostream>
#include<vector>
using namespace std;

int main(){
	long long n,k;
	cin>>n>>k;
	
	vector<long long> a(n);
	long long maximum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maximum=max(maximum,a[i]);
	}
	long long sum=0;
	long long last=0;	
	for(int i=0;i<n;i++)
	{
		if(maximum-a[i]>last){
			sum+=maximum-a[i]-last;
		}
		last=maximum-a[i];
	}
	if(sum>k)
		cout<<0;
	else
		cout<<k-sum+1;
}
