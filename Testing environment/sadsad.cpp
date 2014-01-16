#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
	int a[]={5,6,7,8,3,45,6,7,7,5,4};
	
	sort(a,a+sizeof(a)/4);
	
	for(int *p=a;p<a+sizeof(a)/4;p++)
	{
		cout<<*p<<" ";
	}


}

