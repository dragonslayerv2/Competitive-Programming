#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int t=10;
	cout<<t<<endl;
	while(t--)
		cout<<rand()<<endl;
}
