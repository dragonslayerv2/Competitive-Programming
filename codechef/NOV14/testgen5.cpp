#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int t=10;
	cout<<t<<endl;
	while(t--){
		char type[]={'i','r','b'};
		cout<<'Q';
		int typeNumber = rand()%3;
		cout<<type[typeNumber];
		if(typeNumber!=0){
			cout<<" "<<1+rand()%10<<" "<<1+rand()%10;
		}
		cout<<endl;
	}
}
