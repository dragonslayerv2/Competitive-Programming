#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<limits>
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
	
	long long n;
	cin>>n;
	vector<long long> array;
	array.reserve(n);
	long long MIN=numeric_limits<long long>::max();
	long long S=0;
	for(long long i=0;i<n;i++)
	{
		long long a;
		cin>>a;
		S+=a;
		MIN=min(MIN,a);
		array.push_back(a);
	}
	
	
	
	if(n<10000&&n*S>1000000)
	{	
		set<long long> sums;
		for(long long i=0;i<n;i++)
		{
			long long sum=0;
			for(long long j=i;j<n;j++)
			{
				sum+=array[j];
				sums.insert(sum);
			}
		}
		cout<<sums.size()-1<<endl;
	}
	else
	{
		long long count=0;
		for(long long i=MIN;i<=S;i++)
		{
			if(findsum(array,i))
				count++;
		}
		cout<<count-1<<endl;
	}
}

