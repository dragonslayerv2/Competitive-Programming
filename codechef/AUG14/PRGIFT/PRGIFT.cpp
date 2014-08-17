#include<iostream>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE	
	freopen("test.txt","r",stdin);
	#endif
	
	char yes[] = "YES";
	char no[] = "NO";
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int evenCount = 0;
		
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			evenCount+=((a%2)==0);
		}

		if(k==0&&evenCount==n)
			cout<<no;
		else if(evenCount >=k)
			cout<<yes;
		else
			cout<<no;
		cout<<endl;
	}
}
