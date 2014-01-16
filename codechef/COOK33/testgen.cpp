#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;


int main()
{
	
	int t=100;
	cout<<t<<endl;
	while(t--)
	{
		int n=1+ (rand()%20);
		int k=rand()%(n+1);
		cout<<n<<" "<<k<<endl;
		for(int i=0;i<n;i++)
			cout<<char('a'+(rand()%26));
		cout<<endl;
		for(int i=0;i<n;i++)
			cout<<char('a'+(rand()%26));
		cout<<endl;
		
		
		
	
	}
	


}
