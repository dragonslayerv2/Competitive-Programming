/*
	Name: SQRT function
	Copyright: 
	Author: Shobhit Saxena
	Date: 14/11/13 00:49
	Description: Assumptions. n*n lines in long long limit
						alse n+n lies in long long limit
	
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


int main()
{
	for(int i=0;i<1000000;i++)
	{
		cout<<i<<"=>"<<sqrt(i);
		cin.get();
	}
}
