#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
	srand(time(NULL));
	int t=10;
	cout<<t<<endl;
	while(t--){
		cout<<1+rand()%50<<" "<<1+rand()%50<<endl;
	}
	
	
}
