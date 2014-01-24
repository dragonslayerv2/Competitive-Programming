#include<iostream> 
#include<map>
#include<vector>
using namespace std;

vector<int> numbers;

int count=0;
void permute(int i,int n)
{
	if(i==n)
	{
		map<int,bool> hashing;
		for(int i=0;i<n;i++)
			hashing[(numbers[i]+i)%n]=true;
		if(hashing.size()==n)
			count++;
	}
	else
	{
		for(int j=i;j<n;j++)
		{
			swap(numbers[i],numbers[j]);
			permute(i+1,n);
			swap(numbers[i],numbers
			[j]);
		}
	}
}


int main()
{
	while(1)
	{
	int n;
	cin>>n;
	count=0;
	numbers.resize(n);
	for(int i=0;i<n;i++)
		numbers[i]=i;
	permute(0,n);
	cout<<count<<endl;
}
}
