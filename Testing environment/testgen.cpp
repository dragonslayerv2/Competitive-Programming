#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;


int main()
{
	srand(time(NULL));
	int t=10;
	cout<<t<<endl;
	while(t--)
	{
		int n=1+ (rand()%5);
		int k=1+(rand()%(n));
		cout<<n<<" "<<k<<endl;
		for(int i=0;i<n;i++)
			cout<<char('a'+(rand()%26));
		cout<<endl;
		for(int i=0;i<n;i++)
			cout<<char('a'+(rand()%26));
		cout<<endl;
		
		
		
	
	}
	


}
