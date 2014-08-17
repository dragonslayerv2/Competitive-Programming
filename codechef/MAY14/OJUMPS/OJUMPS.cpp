#include<iostream>
using namespace std;

int main()
{
	long long a;
	cin>>a;
	int res=(a%6);
	if(res==0||res==1||res==3)
		cout<<"yes";
	else
		cout<<"no";
}
