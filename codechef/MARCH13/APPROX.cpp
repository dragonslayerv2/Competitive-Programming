#include<iostream>
using namespace std;

int main()
{
	
	
	
	int t;
	cin>>t;
	while(t--)
	{
		int num=103993%33102;
		int den=33102;
		int n;
		cin>>n;
		
		cout<<3;
		if(n>0)
		{
			cout<<".";
			while(n)
			{
				num=num*10;
				cout<<num/den;
				num=num%den;
				n--;
			}			
		}
		cout<<endl;
	}
	return 0;
}
