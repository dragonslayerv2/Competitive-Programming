#include<iostream>
#include<map>
#include<vector>
using namespace std;


template<class t> bool findsum(t &arr,long long sum)
{
    long long curr_sum = arr[0], start = 0;
    for (long long i = 1; i <=arr.size(); i++)
    {
        while (curr_sum > sum && start < i-1)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        if (curr_sum == sum)
            return true;

        if (i < arr.size())
          curr_sum = curr_sum + arr[i];
    } 
    return false;
}
	

int main()
{
	vector<int> a;
	int n;
	cin>>n;
	a.reserve(n);
	map<long long,bool> sums;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x==0)
			sums[0]=true;
		if(x>0)
			a.push_back(x);
	}
	n=a.size();
	
	long long maxsum=0;
	
	
	for(int i=0;i<n;i++)
	{	
		maxsum+=a[i];
		sums[maxsum]=true;

	}
		
	for(int i=1;i<10&&i<n;i++)
	{
		long long sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=a[j];
			sums[sum]=true;
		}
	}
	
	for(long long i=1;i<maxsum;i++)
	{
		if((sums.find(i)==sums.end())&&findsum(a,a.size(),i))
		{
			sums[i]=true;
		}
		
	}
	cout<<sums.size()-1;
}
