#include<iostream>
using namespace std;


int hamming(string a,string b)
{
	int d=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=b[i])
			d++;
	}
	return d;
}


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string a,b;
		cin>>a>>b;
		
		int count=0;
		for(int i=0;i<n;i++)
		{
			for(int c=1;c<=n-i;c++)
			{
				
				for(int j=0;j<=n-c;j++)
				{
						
					if(hamming(a.substr(i,c),b.substr(j,c))<=k)
					{
						count++;
					}
				}
			}			
		}
		cout<<count<<endl;
	}
	return 0;
}
