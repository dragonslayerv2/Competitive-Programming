#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define MAXQUERY 10
int main()
{
	freopen("test2.txt","w",stdout);
	srand(time(NULL));
	cout<<MAXQUERY<<endl;
	for(int i=0;i<MAXQUERY;i++)
		cout<<1+rand()%15<<endl;
		
}
