#include<iostream>
#include<bitset>
using namespace std;

#define rep(i) for(int i=1;i<(1<<citycount);i++)


bool isdistinct(int a,int b)
{
	return ((a^b)&a)&&((a^b)&b);
}


bool generate(int spoons, int citycount,int current,int spoon[])
{
	if(current==spoons)
	{
		
		for(int i=0;i<spoons;i++)
		{
			
		
			for(int j=i+1;j<spoons;j++)
			{
				if(!isdistinct(spoon[i],spoon[j]))
					return false;
			}
		}
		for(int i=0;i<spoons;i++)
		{
			bitset<10> a=spoon[i];
			cout<<a<<endl;
			
		}
		return true;
	}

	for(int i=1;i<(1<<citycount);i++)
	{
		spoon[current]=i;
		if(generate(spoons,citycount,current+1,spoon))
			return true;
	}
	return false;
}


int main()
{
	for(int i=1;i<=10;i++)
	{
		int spoons[i];
		for(int j=1;j<=i;j++)
		{
	
			if(generate(i,j,0,spoons))
			{
				cout<<i<<" "<<j<<endl;
				break;
			}	
				
		}
	}

}
