#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int t=2;
	cout<<t<<endl;
	while(t--)
	{
		int n=1+rand()%10;
		cout<<n<<endl;
		for(int i=0;i<n;i++)
			cout<<rand()%4<<" ";
		cout<<endl;
		for(int i=0;i<n;i++)
			cout<<rand()%4<<" ";
		cout<<endl;
	}
}
