#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
	
#define nMAX 1000000
int main(){
	srand(time(NULL));
	int n=nMAX;
	for(int i=0;i<n;i++)
		cout<<(char)('a'+rand()%2);
	cout<<endl;
}

