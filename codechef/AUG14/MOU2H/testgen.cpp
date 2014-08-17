#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int main(){
	srand(time(NULL));
	int t=3;
	cout<<t<<endl;
	while(t--){
		int n=1000000;
		cout<<n<<endl;
		while(n--)
			cout<<(rand()%2?"-":"")<<rand()<<" ";
	}
	
}
