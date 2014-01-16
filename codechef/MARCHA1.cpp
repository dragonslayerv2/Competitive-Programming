#include<iostream>
using namespace std;
int value[100];

bool isSum(int n,int m,int future=0,int present=0,int i=0)
{
	if(i>=n) return false;
	if(present+value[i]==m||present+future==m||future==m) return true;
	else if(present>m) return false;
	else if(present+future<m) return false;
	else return isSum(n,m,future-value[i],present+value[i],i+1)||isSum(n,m,future-value[i],present,i+1);
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>value[i];
			sum+=value[i];
		}
		cout<<(isSum(n,m,sum)?"Yes":"No")<<endl;
	}
	return 0;
}
