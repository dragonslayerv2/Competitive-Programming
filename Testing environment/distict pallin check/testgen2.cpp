
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;


int main()
{
	srand(time(NULL));
	string a;
	for(int i=0;i<100;i++)
		a+='a'+(rand()%5);
	cout<<a<<endl;
}
