#include<iostream>
#include<cstdlib>
using namespace std;


int main()
{
	int n=1+(rand()%10000);
	int k=rand()%1000;
	cout<<n<<" "<<k<<endl;
	for(int i=0;i<n;i++)
		cout<<(rand()%2?"-":"")<<rand()%1000<<" ";
}
