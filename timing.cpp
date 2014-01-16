#include<ctime>
#include<iostream>
using namespace std;

int main()
{
	clock_t start;
	clock_t end;
	
	start=clock();
	//---------
	int i=0;
		while(i<1000000) i++;
	//----------------
	end=clock();
	
	cout<<(float(end)-start)/CLOCKS_PER_SEC;
}
