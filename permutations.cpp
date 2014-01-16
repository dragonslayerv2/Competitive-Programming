#include<iostream> 
using namespace std;

char* children[]={"Ankit","Umesh","Shivam","Gambhir","S"};

void permute(int i,int n)
{
	if(i==n)
	{
		for(int i=0;i<5;i++)
			cout<<children[i]<<"\t";
		cout<<endl;
	}
	else
	{
		for(int j=i;j<n;j++)
		{
			swap(children[i],children[j]);
			permute(i+1,n);
			swap(children[i],children[j]);
		}
	}
}


int main()
{
	permute(0,5);
}
