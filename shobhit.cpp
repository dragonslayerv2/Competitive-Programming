#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		int l =1, r =n;
		long long sum = 0;
		
		bool incrementType=true;
		while(l<r){
			
			sum+=abs(l-r);	
			l+=incrementType;
			r-=!incrementType;
		}
		if(n==1){
			cout<<1<<endl;
		}
		else
			cout<<sum<<endl;
	}
}
