#include<iostream>
using namespace std;

int sum(int a,int b){
	int newNumber=0;
	while(a||b){
		newNumber*=10;
		newNumber+=(a+b)%10;
		a/=10;
		b/=10;
	}
	return newNumber;
}
int main(){
	for(int i=1;i<10000;i++){
		bool isPossible=false;
		for(int j=1;j<=i;j++){
			for(int k=1;k<=i;j++){
				if(sum(j,k)==k){
					isPossible=true;
					break;
				}
			}
		}
		if(!isPossible)
			cout<<i<<endl;
	}
}
