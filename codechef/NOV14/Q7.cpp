#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
//------------------------------------------

void mul(double a[27][27],double b[27][27])
{
    double x[27][27];
    for(int i=0;i<26;i++)
    {
    	for(int j=0;j<26;j++)
    	{
    		x[i][j]=0;
    		for(int k=0;k<26;k++)
    		{
    			x[i][j]+=(a[i][k]*b[k][j]);
    		}
    	}
    }
    for(int i=0;i<26;i++)
    {
    	for(int j=0;j<26;j++)
    	{
    		a[i][j]=x[i][j];
    	}
    }
}

void pow(double a[27][27],int n)
{
    double x[27][27];
    for(int i=0;i<26;i++)
    {
    	for(int j=0;j<26;j++)
    	{
    		x[i][j]=a[i][j];
    	}
    }
    
    while(n>1)
    {
    	mul(x,a);
        if(n%2!=0)
        mul(x,a);
        n=n/2;
    }
    for(int i=0;i<26;i++)
    {
    	for(int j=0;j<26;j++)
    	{
    		a[i][j]=x[i][j];
    	}
    }
}
   
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string str;
		cin>>str;
		int l=str.size();
		double arr[27][27];
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<26;j++)
			{
				cin>>arr[i][j];
			}
		}
		
		//cout<<"kit";
		pow(arr,k);
		map<string, int> M;
		double ans=0;
		while(n--)
		{
			//cout<<"hi";
			string a;
			cin>>a;
			if(M.find(a)==M.end())
			{
				double temp=1;
				for(int i=0;i<l;i++)
					temp*=arr[str[i]-'a'][a[i]-'a'];
				ans+=temp;
				M[a]=1;
			}
		}
		printf("%.6lf",ans);
	}
}
