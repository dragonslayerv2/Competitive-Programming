#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int count = 0;
	while(n--){
		int in,capacity;
		cin>>in>>capacity;
		if(in+2<=capacity)
			count++;
	}
	cout<<count;
}
