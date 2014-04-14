#include<iostream>
#include<map>
using namespace std;


int main()
{
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		int a;
		cin>>a;
		map<int,int> elements;
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
			{
				int x;
				cin>>x;
				if(i==a)
					elements[x]++;
			}
		
		int b;
		cin>>b;
		
		int ans;
		int count=0;
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
			{
				int x;
				cin>>x;
				if(i==b)
					elements[x]++;
					
				if(elements[x]==2)
				{
					count++;
					ans=x;
				}
			}
		
		cout<<"Case #"<<T<<": ";
		if(count==0)
			cout<<"Volunteer cheated!";
		else if(count==1)
			cout<<ans;
		else
			cout<<"Bad magician!";
		cout<<endl;
	}
}
