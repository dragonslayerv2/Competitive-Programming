/*
	Name: Check whether a number is fibonacci number or not.
	Copyright: 
	Author: 
	Date: 14/11/13 00:51
	Description: A number is Fibonacci if and only if one or both of (5*n^2 + 4) or (5*n^2 – 4) is a perfect square (Source: Wiki).
*/

#include<iostream>
using namespace std;


long long sqrt(long long n)
{
	long long llimit=0;
	long long ulimit=n;
	long long mlimit;
	while(ulimit>=llimit)
	{
		mlimit=(llimit+ulimit)/2;
		if(mlimit*mlimit<n)
			llimit=mlimit+1;
		else if(mlimit*mlimit>n)
			ulimit=mlimit-1;
		else
			break;
	}
	if(mlimit*mlimit==n)
		return mlimit;
	else if(mlimit*mlimit>n)
		return mlimit-1;
	else
		return mlimit;
}

bool is_perfect_square(long long n)
{
	long long sqrt=::sqrt(n);
	return (sqrt*sqrt)==n;
}
bool isfibonicci(long long n)
{
	return is_perfect_square(5*n*n + 4) || is_perfect_square(5*n*n - 4);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout<<isfibonicci(n)<<endl;
		
	}
}
