#include<iostream>
using namespace std;


const int maxsize=100;

/*
4
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
*/
int det(int a[][maxsize],int n)
{
	int ans=0;
	
	int row=0,col=0;
	
	for(int k=0;k<n;k++)
	{
		int i=row;
		int j=col;
		int product=1;
//cout<<product;
		while(i<n)
		{
//cout<<"*"<<a[i][j];
			product*=a[i][j];
			i++;
			j++;
			j%=n;
		}
		ans+=product;	
//cout<<"+";
		col++;
	}
	
	row=col=0;
	
	for(int k=0;k<n;k++)
	{
		int i=row;
		int j=col;
		int product=1;
//cout<<product;
		while(i<n)
		{
//cout<<"*"<<a[i][j];
			product*=a[i][j];
			i++;
			j--;
			j=(j+n)%n;
		}
		ans-=product;	
//cout<<"+";
		col++;
	}
	return ans;
}


int main()
{
	int a[maxsize][maxsize];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	
	cout<<det(a,n);
}
