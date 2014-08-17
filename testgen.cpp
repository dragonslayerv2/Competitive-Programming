#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

char types[]={'i','r','k','f','b','d','s','p'};

int main()
{
	srand(time(NULL));
	int n=10000;
	cout<<n<<endl;
	int m=10000;
	cout<<m<<endl;
	while(m--)
	{
		char type=types[rand()%(sizeof(types))];
		cout<<type<<" ";
		switch(type)
		{
			case 'i':
			case 'r':
			case 'd':
			case 's':
			case 'p':
			case 'k':	cout<<1+rand()%(n-1);break;
		}
		cout<<endl;
	}
}
