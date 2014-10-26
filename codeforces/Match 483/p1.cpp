#include<iostream>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int i=1;
	int j=n;
	
	int turn=0;
	while(i<=j&&k--){
		if(turn){
			cout<<j<<" ";
			j--;
		}
		else{
			cout<<i<<" ";
			i++;
		}
		turn^=1;
	}
	if(!turn){
		while(j>=i){
			cout<<j<<" ";
			j--;
		}
	}
	else{
		while(j>=i){
			cout<<i<<" ";
			i++;
		}
	}
}
