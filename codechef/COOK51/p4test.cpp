#include<iostream>
using namespace std;

int main(){
	int fibo[100];
	fibo[0]=fibo[1]=1;
	for(int i=2;i<100;i++)
	{
		fibo[i]=fibo[i-1]+fibo[i-2];
		cout<<i<<" "<<fibo[i]<<endl;
	}
	
}
