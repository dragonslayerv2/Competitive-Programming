#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cout<<"Case #"<<t<<": ";
		
		int n,l;
		cin>>n>>l;
		vector<string> a(n),b(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		for(int j=0;j<n;j++)
			cin>>b[j];
			
		vector<int> XOR(l);
		bool isPossible=true;
		for(int i=0;i<n;i++)
			for(int j=0;j<l;j++)
				XOR[j]^=((a[i][j]-'0')^(b[i][j]-'0'));

		for(int i=0;i<XOR.size();i++)
			isPossible=(isPossible&&(!XOR[i]));
		
		if(!isPossible)
			cout<<"NOT POSSIBLE";
		else
		{cout<<"OK";
		}
		cout<<endl;
	}
}
