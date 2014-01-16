#include<iostream>
using namespace std;


inline int gcf(long long a, long long b)
{
   long long temp;    
   while(b)
   {
           temp=a;
           a=b;
           b=temp%b;
   }
   return a;
}


int main()
{
	for(int i=1;i<100;i++)
	{
		long long count=0;
		for(int j=1;j<=i;j++)
			count+=i/j;
	
		cout<<count<<" "<<(i*i)<<endl;;
	
	}
}
