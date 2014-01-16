#include<iostream>
#include<vector>
#include<limits>
#include<map>
using namespace std;

map<long long,map<long long,long long> > hashvalue;
map<long long,map<long long,bool> > exists;


long long solve(int jars,int Tcoins,int Rcoins)
{
	if(exists[jars][Tcoins])
		return hashvalue[jars][Tcoins];
	else
	{
		long long result;
		if((Tcoins/jars)*jars>=Rcoins)
			result= Rcoins;
		else
		{
			long long minimum = numeric_limits<long long>::max();
			for(int i=0;i<=Tcoins/jars;i++)
				minimum=min(minimum,1+jars*i+solve(jars-1,Tcoins-jars*i,Rcoins-jars*i));
			result=minimum;
		}
		exists[jars][Tcoins]=true;
		hashvalue[jars][Tcoins]= result;
		return hashvalue[jars][Tcoins];
	}
}
int main()
{
	freopen("output2.txt","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		hashvalue.clear();
		exists.clear();
		int jars,Tcoins,Rcoins;
		cin>>jars>>Tcoins>>Rcoins;
		long long output=solve(jars,Tcoins,Rcoins);
		cout<<"Case #"<<i<<": "<<output<<endl;
	}
}
