#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int t=10;
	cout<<t<<"\n";
	while(t--){
		long long random = rand();
		long long n=1+(random*random)%10000000LL;
		int m=1+rand()%100000;
		cout<<n<<" "<<m<<"\n";
	}
	
}
