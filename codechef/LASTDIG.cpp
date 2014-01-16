#include<iostream>
using namespace std;

int D[]={0,1,4,3,8,5,2,7,6,9};


int d(int i)
{
	
	int ans=0;
	while(i)
	{
		ans+=D[i%10];
		i=i/10;
	}
	return ans%10;
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		
		int ans=45*(b/10-a/10);
		for(int i=(b/10)*10;i<b+1;i++)
			ans+=d(i);
		for(int i=(a/10)*10;i<a;i++)
			ans-=d(i);
		
		cout<<ans<<endl;
	}
	return 0;
}
