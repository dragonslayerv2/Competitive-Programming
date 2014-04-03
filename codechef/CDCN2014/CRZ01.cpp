#include<iostream>
#include<set>
using namespace std;

int main()
{
//	freopen("test.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		multiset<int> factors;
		for(int i=2;i<=k;i++)
			while(k%i==0)
			{	
				factors.insert(i);
				k/=i;				
			}
		
		while(factors.size()>n)
		{
			multiset<int>::iterator i=factors.begin();
			multiset<int>::iterator j=(++i);
			
			int a=*i;
			int b=*j;
			
			factors.erase(factors.begin());
			factors.erase(factors.begin());
			
			
			factors.insert(a*b);
			
		}
		
		double sum=0;
		for(multiset<int>::iterator i=factors.begin();i!=factors.end();i++)
			sum+=*i;
		if(factors.size()<n)
			sum+=n-factors.size();
		cout.setf(ios::fixed);
		cout.precision(6);
		cout<<sum<<endl;
	}
}
