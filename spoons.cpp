#include<iostream>
#include<vector>
using namespace std;

unsigned long long nC2(unsigned long long n)
{
	return (n*(n-1))/2;
}

unsigned long long getans(unsigned long long l,unsigned long long h,unsigned long long ans)
{
	unsigned long long m=(l+h)/2;
	unsigned long long mC2=nC2(m);
	
	if(mC2==ans||(mC2>ans&&nC2(m-1)<ans))
		return m;
	else if(mC2>ans)
		return getans(l,m,ans);
	else
		return getans(m,h,ans);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		unsigned long long n;
		cin>>n;
		unsigned long long ans;
		if(n==0)
			ans=0;
		if(n==1)
			ans=1;
		else if(n==2)
			ans=2;
		else if(n==3)
			ans=3;
		else
			ans=getans(1,1700000000LL,n);
	
		cout<<ans<<endl;
	}
}
