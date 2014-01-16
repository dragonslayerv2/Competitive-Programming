#include<iostream>
#include<cstdlib>
using namespace std;


int main()
{
	cout<<10000<<endl;
	for(int i=0;i<10000;i++)
	{
		cout<<rand()%1000<<" "<<1000+(rand()%1000000)<<endl;
	}
}
