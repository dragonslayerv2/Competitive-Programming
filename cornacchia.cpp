/*
	Name: Cornacchia Algorithm
	Copyright: 
	Author: DragonSlayerX
	Date: 14/10/13 13:38
	Description: Cornacchia algorithm is used to find a solution of equations of the form x^2+d*y^2=m where 1<=d <=m
				Overall complexity O(m)	
*/


#include<iostream>
#include<cmath>
using namespace std;


class NO_SOLUTION_ERROR{};

pair<long long,long long> cornacchia_solve(long long m,long long d)
{
		long long r1=m;
		long long r2;
		for(r2=1;r2<=m/2;r2++)
			if((r2*r2)%r1==r1-d)
				break;
	
		if(r2>m/2)
			throw NO_SOLUTION_ERROR();
	
		while(r1*r1>=m)
		{
			if(r2==0)
				throw NO_SOLUTION_ERROR();
			long long temp=r1%r2;	
			r1=r2;
			r2=temp;
		}		
		int x=r1;
		int y=sqrt(m-x*x)/d;
		if(x*x+d*y*y!=m)
			throw NO_SOLUTION_ERROR();
		else
			return make_pair(x,y);
}
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		int m;
		cin>>m;
		try	
		{	
			cornacchia_solve(m*m,1);
			cout<<"PERFECT";
		}catch(...)
		{
			cout<<"IMPERFECT";
		}
		cout<<endl;
	}
}
