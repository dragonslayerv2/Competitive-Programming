#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	int t=100;
	cout<<t<<"\n";
	while(t--){
		int l=rand()%1000;
		int r=rand()%1000 + l;
		int n=rand()%((r-l)/2+1);
		cout<<l<<" "<<r<<" "<<n<<"\n";
	}
}
