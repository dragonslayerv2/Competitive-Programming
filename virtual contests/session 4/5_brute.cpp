#include<iostream>
#include<set>
#include<vector>
using namespace std;

long long count=0;
vector<bool> bank;
void brute(int n,int k,int i=0)
{
	//cout<<i<<k<<n<<endl;;
	if(k>n)
		return;
	else if(k<0)
		return;
	else if(n==i&&k==0)
	{
		count++;
	}
	else if(n==i)
		return;
	else
	{
		for(int j=0;j!=bank.size();j++)
		{
			if(bank[j])
			{
				bank[j]=false;
				if(j-i==1||j-i==-1)
					brute(n,k-1,i+1);
				else
					brute(n,k,i+1);	
				bank[j]=true;
			}
		}
	}
}
int main()
{
	for(int n=0;n<10;n++)
	{
		for(int k=0;k<=n;k++)
		{
			bank.clear();
			bank.resize(n);
			for(int i=0;i<n;i++)
				bank[i]=true;
			count=0;
		
			brute(n,k);
			cout<<count<<"\t";
		}
		cout<<endl;
	}
}
