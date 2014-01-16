#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	clock_t start=clock();
	for(int i=0;i<1000000000;i++);
	clock_t end=clock();

	cout<<(end-float(start))/CLK_TCK;

}