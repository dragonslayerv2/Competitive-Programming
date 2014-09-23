#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(NULL));
	int n=1+rand()%300000;
	cout<<n<<endl;
	int i;
	for(i=0;i<n;i++)
   	{
	   cout<<rand()%1000000+1;
	   if(i<n-1)
	   	cout<<" ";
    }
    cout<<endl;
}
 
