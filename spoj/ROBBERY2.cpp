#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,k;
		cin>>n>>k;
		
		long long rounds=((-1+sqrt(double(1+8*n)))/(2*k));
		
		n-=((rounds*k)*(rounds*k+1))/2;
		
		for(int i=1;i<=k;i++)
		{
			long long solution=0;
			if(rounds>0)
				solution=(rounds*((2*i+(rounds-1)*k)))/2;
			
			long long term=i+(rounds)*k;
				
			solution+=min(term,n);
			n-=min(term,n);
			cout<<solution<<" ";			
			
			
		}
		cout<<endl;
	}
	
}
