#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		char a[200][200];	
		for(int i=0;i<200;i++)
		{
			for(int j=0;j<200;j++)
				a[i][j]='0';
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		
		int scared[200][200]={0};
		bool isleft[200][200]={0};
	
		
		for(int i=n;i>=1;i--)
		{
			for(int j=m;j>=1;j--)
			{
				if(i==n&&j==m)
				{
					scared[i][j]=(a[i-1][j]-'0')+(a[i][j-1]-'0');
					if(a[i][j]=='1')
						scared[i][j]++;
					
				}
				else if(i==n)
				{
					
					scared[i][j]=(a[i-1][j]-'0')+(a[i][j-1]-'0')+scared[i][j+1];
					isleft[i][j]=true;
				//	cout<<i<<j<<"=>"<<scared[i][j]<<endl;
				}
				else if(j==m)
				{
					scared[i][j]=(a[i-1][j]-'0')+(a[i][j-1]-'0')+scared[i+1][j];
					isleft[i][j]=false;
				}
				else
				{
					int lscared=(a[i-1][j]-'0')+(a[i][j-1]-'0')+(isleft[i][j+1]?(a[i+1][j]-'0'):0)+scared[i][j+1];
					int uscared=(a[i-1][j]-'0')+(a[i][j-1]-'0')+(isleft[i+1][j]?0:(a[i][j+1]-'0'))+scared[i+1][j];
					
					if(lscared<uscared)
					{
						isleft[i][j]=true;
						scared[i][j]=lscared;						
					}
					else
					{
						isleft[i][j]=false;
						scared[i][j]=uscared;						
					}
				}
			}
		}
      //  void print(int scared[200][200],int n,int m);
	//	print(scared,n,m);
		cout<<scared[1][1]<<endl;
	}
}
/*
void print(int scared[200][200],int n,int m)
{
 for(int i=1;i<=n;i++)
 {
 	for(int j=1;j<=m;j++)
    {
    	cout<<scared[i][j]<<" ";
    }
    cout<<endl;
 }
}*/
