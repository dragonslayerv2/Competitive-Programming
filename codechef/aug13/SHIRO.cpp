#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

vector<vector<double> > lookuptable;
vector<vector<bool> > ispresent;

double solve(vector<int> & flags,vector<double> & probability,int rest_sum, int present_sum=0,int i=0)
{
	//cout<<"At "<<i<<" "<<rest_sum<<endl;
	if(i==flags.size())
	{
		if(rest_sum<=present_sum)
			return 1;
		else
			return 0;
	}
	else if(rest_sum<=present_sum)
	{
		return 1;
	}
	
	else
	{
		//cout<<"Going for lookup talble";	
		double myans=0;
		if(ispresent[i+1][rest_sum-flags[i]])
		{
				myans= probability[i]*lookuptable[i+1][rest_sum-flags[i]];
		//		cout<<"GOt "<<i+1<<" "<<rest_sum-flags[i]<<endl;
		}
		
		else
		{
			ispresent[i+1][rest_sum-flags[i]]=true;
			lookuptable[i+1][rest_sum-flags[i]]=solve(flags,probability,rest_sum-flags[i],present_sum+flags[i],i+1);
			myans= probability[i]*lookuptable[i+1][rest_sum-flags[i]];
		}
		// ----------- no selected----
		if(ispresent[i+1][rest_sum])
			myans+= (1-probability[i])*lookuptable[i+1][rest_sum];
		else
		{
			ispresent[i+1][rest_sum]=true;
			lookuptable[i+1][rest_sum]=solve(flags,probability,rest_sum,present_sum,i+1);
			myans+= (1-probability[i])*lookuptable[i+1][rest_sum];
		//	cout<<"GOt "<<i+1<<" "<<rest_sum<<endl;
		}
		return myans;
	}
}

int rest_sum(vector<int> & array)
{
	int sum=0;
	for(int i=0;i<array.size();i++)
	{
		sum+=array[i];
	}
	return sum;
}
//#define TEST
int main()
{
	#ifdef TEST
		freopen("testshiro.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		vector<int> flags;
		vector<double>  probability;
		int n;
		cin>>n;
		flags.reserve(n);
		probability.reserve(n);
		
		for(int i=0;i<n;i++)
		{
			int flag;
			cin>>flag;
			flags.push_back(flag);	
		}
		for(int i=0;i<n;i++)
		{
			double prob;
			cin>>prob;
			probability.push_back(prob/100);	
		}
		int sum=rest_sum(flags);
		
		lookuptable.assign(n+10,vector<double>(sum+100,0));
		ispresent.assign(n+10,vector<bool>(sum+100,0));
	
		cout<<fixed<<setprecision(6)<<solve(flags,probability,sum)<<endl;
	}
}
