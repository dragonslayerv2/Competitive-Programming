#include<iostream>
#include<vector>
using namespace std;

inline int GCF(long long a, long long b)
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

vector<long long> nCn2;

int main()
{
	nCn2.push_back(1);
	while(nCn2.back()<=1000000000000000000LL)
	{
		if(nCn2.size()%2)
		{
			nCn2.push_back(nCn2.back()*2);
		}
		else
		{
			
			long long n=nCn2.size();
			
			long long den=(n+2)/2;
			long long num=nCn2.back();
			long long gcf=GCF(num,den);
			num/=gcf;
			den/=gcf;
			num*=(n+1)/den;
			nCn2.push_back(num);
		}
		
	}
	cout<<nCn2.size()<<endl;
	cout<<nCn2.back();
}
