#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<long long> minhash;
vector<bool> minexists;
vector<long long> maxhash;
vector<bool> maxexists;

long long max(long long j,vector<long long> &numbers);
long long min(long long j,vector<long long> &numbers)
{
	if(j==0)
		return numbers[0];
	else if(minexists[j])
		return minhash[j];
	else
	{
		long long multiply1,multiply2;
		multiply1=numbers[j]*min(j-1,numbers);
		multiply2=numbers[j]*max(j-1,numbers);
			
		long long subtract=min(j-1,numbers)-numbers[j];
		long long addition=numbers[j]+min(j-1,numbers);
		long long result=min(multiply1,subtract);
		result=min(result,multiply2);
		result=min(result,addition);
//		cout<<"MIN AT "<<j<<subtract<<" "<<addition<<" "<<multiply<<endl;
		minhash[j]=result;
		minexists[j]=true;
		return result;
	}
}

long long max(long long j,vector<long long> &numbers)
{
	if(j==0)
		return numbers[j];
	else if(maxexists[j])
		return maxhash[j];
	else
	{
		long long multiply1;
		long long multiply2;
			multiply1=numbers[j]*max(j-1,numbers);
			multiply2=numbers[j]*min(j-1,numbers);
			
		long long subtract=max(j-1,numbers)-numbers[j];
		long long addition=numbers[j]+max(j-1,numbers);
		long long result=max(multiply1,subtract);
		result=max(result,multiply2);
		result=max(result,addition);
		maxhash[j]=result;
		maxexists[j]=true;
		return result;
	}
}



int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		minhash.clear();
		minexists.clear();
		maxhash.clear();
		maxexists.clear();
		
		long long n;
		cin>>n;
		minhash.resize(n);
		maxhash.resize(n);
		minexists.resize(n);
		maxexists.resize(n);
		vector<long long> numbers(n);
		for(long long i=0;i<n;i++)
			cin>>numbers[i];
		cout<<min(n-1,numbers)<<endl;	
	}
}
