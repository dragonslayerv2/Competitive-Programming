#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define MAXQUERY 1000
int main()
{
	freopen("test7.txt","w",stdout);
	srand(time(NULL));
	cout<<MAXQUERY<<endl;
	for(int i=0;i<MAXQUERY;i++)
	{
		long long a=rand();
		a*=rand();
		a*=rand();
		a%=100000000000LL;
		a*=rand();
		a%=1000000000000000000LL;
		cout<<a<<endl;
	}
		
}
