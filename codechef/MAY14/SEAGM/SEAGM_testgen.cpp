#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;

int main()
{
	srand(time(NULL));
	int t=10;
	cout<<t<<endl;
	while(t--)
	{
		int n=50+rand()%50;
		cout<<n<<endl;
		for(int i=0;i<n;i++)
			cout<<1+rand()%100<<" ";
		cout<<endl;
	}	
}
