#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
	freopen("p2.txt","r",stdin);
	int t;
	cin>>t;
	getchar();
	while(t--){
		int num1,num2,den1,den2;
		char s[1000];
		cin.getline(s,sizeof(s));
		cout<<s<<endl;
		
		sscanf(s,"%d",&num1);
		
		
		
		int numfinal = num1*den2+num2*den1;
		int denfinal = den1*den2;
		int gcd = __gcd(numfinal,denfinal);
		denfinal =denfinal/gcd;
		numfinal = numfinal/gcd;
		/*cout<<numfinal;
		if(denfinal!=1)
			cout<<"/"<<denfinal;
		cout<<endl; */
	}	
}
