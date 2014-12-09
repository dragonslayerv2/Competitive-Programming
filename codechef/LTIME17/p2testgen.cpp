#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int t=1;
	cout<<t<<endl;
	while(t--){
		cout<<3+(rand()%2)<<" "<<rand()<<endl;
	}
}
