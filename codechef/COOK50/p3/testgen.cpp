#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int t=50;
	cout<<t<<endl;
	while(t--){
		int n=100000;
		cout<<n<<endl;
		while(n--)
			cout<<1+rand()%1000000<<" ";
		cout<<endl;
	}
}
