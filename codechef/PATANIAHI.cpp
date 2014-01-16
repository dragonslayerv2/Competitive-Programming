#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long MOD = 1000000007;


long long solve(vector<int> &array,long long l=0,long long r=0,int i=0)
{
	if(i==array.size())
		return 1;
		
	else
	{
		long long count=0;
		if(l+array[i]>=r)
		{
			count+=solve(array,l+array[i],r,i+1);
		}
		 if(l>=r+array[i])
		{
			count+=solve(array,l,r+array[i],i+1);
		}
		return count;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for(int i=0;i<n;i++)
		{
			array[i]=1<<i;
		}
		vector<int> arrayini=array;
		long long count=0;
		do
		{
			count+=solve(array);
			next_permutation(array.begin(),array.end());	
		}while(array!=arrayini);
		cout<<count<<endl;
	}
}
