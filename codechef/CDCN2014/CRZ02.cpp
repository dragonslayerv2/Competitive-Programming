#include<iostream>
#include<vector>
using namespace std;

#define MOD (1000000000+7)
#define MAX 1000005
int main()
{
	vector<int> fibo(MAX);
	fibo[1]=1;
	fibo[2]=1;
	
	for(int i=3;i<MAX;i++)
		fibo[i]=(fibo[i-1]+fibo[i-2])%MOD;
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<fibo[n+1]<<endl;
	}
}
