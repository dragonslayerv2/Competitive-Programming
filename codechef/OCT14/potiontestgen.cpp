#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int t=1;
	cout<<"1"<<endl;
	while(t--){
		cout<<"1 1 1 "<<rand()%10<<endl;
		cout<<rand()%10<<" "<<rand()%10<<" "<<rand()%10<<endl;
	}
	
}
