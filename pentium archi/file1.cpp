#include<iostream>
#include"rdtsc.h"
using namespace std;

int main()
{
	unsigned long long a,b;
	a=rdtsc();
	b=rdtsc();
	cout<<b-a;
}
