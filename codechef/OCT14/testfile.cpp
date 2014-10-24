#include<iostream>
#include<time.h>
#include<cstdlib>
#include<set>
using namespace std;
//------------------------------------------

int main()
{
	srand(time(NULL));
	int n;
	n=rand()%10;
	cout<<n<<endl;
	for(int i=0;i<n;i++)
	{
			cout<<rand()%10<<" "<<rand()%10<<endl;
	}
}
