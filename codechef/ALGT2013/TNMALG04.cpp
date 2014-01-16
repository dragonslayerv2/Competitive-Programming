#include<iostream>
#include<cstring>
using namespace std;

unsigned long long C(int n)
{
         unsigned long long c=1;
         for(int i=2;i<=n;i++)
         {
                 c=(2*(2*i-1)*c)/(i+1);
         }
         return c;
}


int main()
{
    int t;
	char c[100];
	cin>>t;
	while(t--)
	{
		cin>>c;
		cout<<C(strlen(c)-1)<<endl;
	}
    
}
