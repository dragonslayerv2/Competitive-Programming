#include<iostream>
using namespace std;


#define MAX 1010
int dif(char *a,char *b,int la,int lb,int k,int diftable[MAX][MAX],int counttable[MAX][MAX])
{
//	cout<<"checking for"<<la<<" "<<lb<<endl;
	int ra=la;
	int rb=lb;
	int count=0;
	int len=1;
	while(a[ra]&&b[rb])
	{
//		cout<<a[ra]<<"!="<<b[rb]<<" ";
		count+=a[ra]!=b[rb];
//		cout<<"count="<<count<<endl;
		if(count>k)
			break;
		
		ra++;
		rb++;
		len++;		
	}
	diftable[la][lb]= len-1;
	counttable[la][lb]=count;
}


int diftable[MAX][MAX];
int counttable[MAX][MAX];

void debug(int n)
{
	//--------DEbug--------------
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<diftable[i][j]<<"\t";
			}
			cout<<endl;
		}
}

int main()
{
	int t;
	cin>>t;
	int n,k;
	while(t--)
	{
		cin>>n>>k;
		char a[MAX],b[MAX];
		cin>>a>>b;
		
		long long ans=0;
		for(int la=0;la<n;la++)
		{
			dif(a,b,la,0,k,diftable,counttable);
		}
			
		
		for(int lb=1;lb<n;lb++)
		{
			dif(a,b,0,lb,k,diftable,counttable);
			
		}
		
		
		for(int la=1;la<n;la++)
		{
			for(int lb=1;lb<n;lb++)
			{
				int count=counttable[la-1][lb-1]-(a[la]!=b[lb]);
				int len=diftable[la-1][lb-1]-1;
				int ra=la+len;
				int rb=lb+len;
				
				while(count<=k&&a[ra]&&b[rb])
				{
					ra++;
					rb++;
					count+=a[la]!=b[lb];
					
					len++;
				} 
				diftable[la][lb]=len;
				
				counttable[la][lb]=count;
			}
		}
		ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				ans+=diftable[i][j];
			}
		}
		cout<<ans<<endl;
		
		//debug(n);
	}
	return 0;
}
