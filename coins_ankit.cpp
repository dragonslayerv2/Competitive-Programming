#include<iostream>
using namespace std;


bool recurse(int coins,int turn)
{
	if(coins<=1)
		return false;
	else
	{
		if((!recurse(coins-1,turn*-1))||(!recurse(coins-2,turn*-1))||(!recurse(coins-3,turn*-1)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
int main()
{
	for(int i=1;i<=21;i++)
	{
		cout<<i<<"=> "<<recurse(i,1)<<endl;
	}
	
}
