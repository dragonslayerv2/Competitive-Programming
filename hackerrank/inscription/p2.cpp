#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		
		int total=b-a+1;
		int errorCases=0;
		while(a%3!=1)
			a++;
		if(a<=b)
			errorCases=1+(b-a)/3;
		
		cout<<total-errorCases<<endl;
	}
}
