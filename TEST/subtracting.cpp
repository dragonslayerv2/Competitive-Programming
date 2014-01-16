#include<iostream>
using namespace std;

inline int gcf(int a, int b)
{
   int temp;    
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
	for(int i=1;i<1000000;i++)
	{
		for(int j=i;j<1000000;j++)
		{
			int n=i,m=j;
			while(n!=m)
			{
				if(n>m)
					n=n-m;
				else
					m=m-n;
			}
			if(n!=gcf(i,j))
				cout<<n<<endl;
		}
	}	

}
