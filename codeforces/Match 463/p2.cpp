#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	long long start, energy;
	start=energy=0;
	long long ans=0;
	while(n--){
		long long height;
		cin>>height;
		start-=height;
		
		if(start+energy<0){
			ans-=start+energy;
			energy=0;
		}
		else{
			energy+=start;
		}
		start=height;
	}
	cout<<ans;
}
