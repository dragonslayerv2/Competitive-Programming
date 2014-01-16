#include<iostream>
using namespace std;



struct x
{
	int y:1;
};
int main()
{
	x ob;
	cout<<sizeof(x);	
}
	
