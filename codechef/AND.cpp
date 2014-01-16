#include<iostream>
#include<vector>
using namespace std;


int main()
{
	
		int n;
		cin>>n;
		vector<long long> digits(64);
		
		while(n--)
		{
			int a;
			cin>>a;
			int i=0;
			while(a)
			{
				digits[i]+=(a&1);
				a>>=1;
				i++;
			}		
		}
		
		long long pow2=1;
		long long sum=0;
		for(int i=0;i<64;i++)
		{
				sum+=pow2*((digits[i]*(digits[i]-1))/2);
				
			pow2*=2;
		}
		cout<<sum<<endl;
	
}
