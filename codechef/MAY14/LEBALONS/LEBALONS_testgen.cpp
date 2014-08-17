#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;


int main()
{
	srand(time(NULL));
	int t=1;
	cout<<t<<endl;
	
	while(t--)
	{
		int n=10,m=rand()%n;
		cout<<n<<" "<<m<<endl;
		for(int i=0;i<n;i++)
			cout<<1+rand()%n<<" "<<1+rand()%5<<endl;
	}
}
