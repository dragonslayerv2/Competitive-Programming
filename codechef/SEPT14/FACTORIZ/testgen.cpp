#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int t=1+rand()%10;
	cout<<t<<endl;
	while(t--){
		int num=1+rand()%1000;
		cout<<1+(rand()%9);
		num--;
		while(num--){
			cout<<rand()%10;
		}
		cout<<endl;
	}
}
