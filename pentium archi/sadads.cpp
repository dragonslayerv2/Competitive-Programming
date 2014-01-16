#include<iostream>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<limits>
using namespace std;

vector<int> sums;
template<class t> bool findsum(t &arr,long long sum)
{
    long long curr_sum = arr[0], start = 0;
    for (long long i = 1; i <=arr.size(); i++)
    {
        while (curr_sum > sum && start < i-1)
        {
            curr_sum = curr_sum - arr[start];
            start++;
            sums[curr_sum]=true;
        }
		sums[curr_sum]=true;
        if (curr_sum == sum)
            return true;

        if (i < arr.size())
          curr_sum = curr_sum + arr[i];
    } 
    return false;
}

#define GETCHAR getchar_unlocked

inline int readlong() 
{
	int flag=1;
    long long n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
    }
    return n;
}


int main()
{
	long long n;
	n=readlong();
	vector<long long> array;
	array.reserve(n);
	long long MIN=numeric_limits<long long>::max();
	long long S=0;
	for(long long i=0;i<n;i++)
	{
		long long a;
		a=readlong();
		S+=a;
		MIN=min(MIN,a);
		array.push_back(a);
	}
	
	
	
	if(n<2000)
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
		sums.resize(S+1);
		for(long long i=MIN;i<=S;i++)
		{
			if(!sums[i])
				findsum(array,i);
		}
		long long count=0;
		for(long long i=MIN;i<=S;i++)
		{
			if(sums[i])
				count++;
		}
		cout<<count-1<<endl;
	}
}

