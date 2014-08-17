#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

struct balloon
{
	int cost,colour;
	bool operator <(const balloon &b2) const
	{
		return colour<b2.colour;
	}
		
};

typedef long long ll;
vector<balloon> B;
vector<long long> costSuffix,colourSuffix;
map<pair<int,long long>,pair<long long,long long> > DP;
int n,m;

pair<long long,long long> solve(int i,long long taken,int count)
{
	if(DP.find(make_pair(i,taken))==DP.end())
	{
		if(i==B.size())
		{
			if(count>=m)
				DP[make_pair(i,taken)]=make_pair(0,1);
			else
				DP[make_pair(i,taken)]=make_pair(0,0);	
		}
		else
		{
			// OPTIMISATIONS 
			if(count>=m)
				DP[make_pair(i,taken)]=make_pair(costSuffix[i]*(((ll)1)<<(B.size()-i-1)),(((ll)1)<<(B.size()-i)));
			else if(colourSuffix[i]<(m-count))
				DP[make_pair(i,taken)]=make_pair(0,0);
			else
			{
				pair<long long,long long> currentSolution1,currentSolution2;
				currentSolution1=solve(i+1,taken,count);
				
				currentSolution2=solve(i+1,(taken|(((ll)1)<<B[i].colour)),count+((taken|(((ll)1)<<B[i].colour))>0));
				currentSolution2.first+=B[i].cost*currentSolution2.second;
				
				if(!currentSolution1.second&&!currentSolution2.second)
					DP[make_pair(i,taken)]=make_pair(0,0);
					
				else if(!currentSolution1.second)
					DP[make_pair(i,taken)]=currentSolution2;
				else if(!currentSolution2.second)
					DP[make_pair(i,taken)]=currentSolution1;
				else 
					DP[make_pair(i,taken)]=make_pair(currentSolution1.first+currentSolution2.first,currentSolution1.second+currentSolution2.second);	
			}
		}	
	}
	return DP[make_pair(i,taken)];
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		
		B.assign(n,balloon());
		
		for(int i=0;i<n;i++)
			cin>>B[i].colour>>B[i].cost;
		
		sort(B.begin(),B.end());
		costSuffix.assign(n,0);
		colourSuffix.assign(n,0);
		
		colourSuffix[n-1]=1;
		costSuffix[n-1]=B[n-1].cost;
		long long alreadyTaken=(((ll)1)<<(B[n-1].colour));
		for(int i=n-2;i>=0;i--)
		{
			costSuffix[i]=B[i].cost+costSuffix[i+1];
			colourSuffix[i]=colourSuffix[i+1];
			if(!(alreadyTaken&(((ll)1)<<(B[i].colour))))
			{
				alreadyTaken|=(((ll)1)<<(B[i].colour));
				colourSuffix[i]++;
			}
				
			
		}
		
		DP.clear();
		pair<long long,long long> solution=solve(0,0,0);
		
		cout.setf(ios::fixed);
		cout.precision(6);
		if(solution.second==0)
			cout<<(0.0)<<endl;
		else
			cout<<((double)solution.first)/solution.second<<endl;
	}
}
