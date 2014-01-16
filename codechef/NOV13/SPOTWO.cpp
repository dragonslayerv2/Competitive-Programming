#include<iostream>
using namespace std;


#define MOD 1000000007

long long power[]={2, 1024, 976371285, 688423210, 905611805, 607723520, 235042059, 255718402, 494499948, 140625001, 291251492, 25600497, 959366170, 836339738, 621966918, 264444359, 271283348, 952065854, 719476260, 28918236LL, 894102506LL, 663968931LL, 721365950LL, 70015478LL, 881107223LL, 331368790LL}; 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i=0;
		long long solution=1;
		while(n)
		{
			if(n&1)
			{
				solution*=power[i];
				solution%=MOD;
			}
			i++;
			n>>=1;	
		}
		solution*=solution;
		solution%=MOD;
		cout<<solution<<endl;
	}	
}
