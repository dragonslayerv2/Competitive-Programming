#include<iostream>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b;
		cin>>n>>a>>b;
		int a1=0,a0=0,b1=0,b0=0;
		while(a)
		{
			if(a&1)
				a1++;
			a>>=1;
		}
		
		while(b)
		{
			if(b&1)
				b1++;
			b>>=1;
		}	
		
		a0=n-a1;
		b0=n-b1;
		
		int tot1=min(a1,b0)+min(b1,a0);
		
		int ans=1<<(n-1);
		
		while(tot1>1)
		{
			ans=ans|(ans>>1);
			tot1--;
		}
		if(a1==0 &&b1==0) cout<<0<<endl;
		else cout<<ans<<endl;		
	}
	return 0;
}
