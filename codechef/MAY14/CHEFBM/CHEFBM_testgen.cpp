#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int n,m,p;
	n=1+rand()%3;
	m=1+rand()%3;
	p=rand()%5;
	cout<<n<<" "<<m<<" "<<p<<endl;
	while(p--)
		cout<<1+rand()%n<<" "<<1+rand()%m<<endl;
}
