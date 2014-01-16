#include<iostream>
using namespace std;

int main()
{
	char* children[]={"Ankit","Umesh","Shivam","Gambhir","Surbhi"};
	for(int i=0;i<(1<<5);i++)
	{
		int n=i;
		for(int j=0;j<5;j++)
		{
			if(n&1)
				cout<<children[j]<<"\t";
		
			n=n>>1;
		}
		cout<<endl;
	}

}
