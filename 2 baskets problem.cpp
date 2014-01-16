#include<iostream>
#include<utility>
using namespace std;



ostream & operator <<(ostream &stream,pair<int,int> &bowl)
{
	stream<<"( "<<bowl.first<<", "<<bowl.second<<" )";
	return stream;
}
int func(int a,int b,int L)
{
	if(b<a)
		swap(a,b);
	
	pair<int,int> bowl;
	while(bowl.first!=L&&bowl.second!=L)
	{
		cout<<bowl<<endl;
		if(bowl.second==b)
			bowl.second=0;
		// fill bowl a
		bowl.first=a;
		// pour it into b
		bowl.second+=a;
		if(bowl.second>b)
		{
			bowl.first=bowl.second-b;
			bowl.second=b;
		}
		if(bowl.second==b)
		{
			bowl.second=bowl.first;
			bowl.first=0;	
		}
	}
	cout<<bowl<<endl;
	cin.get();
}

int main()
{

	
}
