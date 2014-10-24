#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	srand(time(NULL));
	t=1000;
	cout<<t<<"\n";
	while(t--){
		long long x,n,m;
		x=(rand()*(long long)rand()*rand())%10000000000000000LL;
		m=(rand()*(long long)rand()*rand())%10000000000000000LL;
		n=1+(rand()*(long long)rand()*rand())%10000000000000000LL;
		cout<<x<<" "<<m<<" "<<n<<"\n";
	}
}
