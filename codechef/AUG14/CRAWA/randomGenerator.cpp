#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int main(){
	srand(time(NULL));
	int t=10000;
	#define MAX 100;
	cout<<t<<endl;
	while(t--)
	{
		cout<<((rand()%2)==0?"-":"");
		cout<<rand()%MAX;
		cout<<" ";
		cout<<((rand()%2)==0?"-":"");
		cout<<rand()%MAX;
		cout<<endl;
	}
	
}
