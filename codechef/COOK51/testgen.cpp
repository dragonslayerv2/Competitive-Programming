#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	int t=100000;
	cout<<t<<"\n";
	while(t--){
		int l=rand()%100000 ;
		int r=rand()%(100000000-l) + l;
		int n=1+rand();
		cout<<l<<" "<<r<<" "<<n<<"\n";
	}
}
