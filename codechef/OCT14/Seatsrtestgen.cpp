#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
	srand(time(NULL));
	int t=10;
	cout<<t<<endl;
	
	while(t--){
		int aLen=100;
		int bLen=100;
		while(aLen--)
			cout<<(char)('a'+rand()%2);
		cout<<endl;
		while(bLen--)
			cout<<(char)('a'+rand()%2);
		cout<<endl;
		cout<<1<<" "<<1<<" "<<100<<endl;
	}
}
