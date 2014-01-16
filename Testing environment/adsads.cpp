#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
	int t=500000;
	ofstream outfile("test.txt");
	outfile<<t<<endl;
	while(t--)
	{
		outfile<<rand()%100000<<" "<<rand()%100000<<endl;
	}
	

}
