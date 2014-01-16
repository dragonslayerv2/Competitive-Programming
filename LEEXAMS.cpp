#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<int,bool> ispresent;
double totalprob=0;

void dfs(vector<double> &prob,vector<int> &first,vector<int> &second,double probability=1,int current=0)
{
	if(current==prob.size())
	{
		totalprob+=probability;
	
		return;
	}

	if(!ispresent[first[current]])
	{
		ispresent[first[current]]=true;

		dfs(prob,first,second,probability*prob[current],current+1);
		ispresent[first[current]]=false;
	}
	if(!ispresent[second[current]])
	{
		ispresent[second[current]]=true;

		dfs(prob,first,second,probability*(1-prob[current]),current+1);
		ispresent[second[current]]=false;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		totalprob=0;
		int n;
		cin>>n;
		vector<double> prob(n); 
		vector<int> first(n); 
		vector<int> second(n);
		for(int i=0;i<n;i++)
		{
			cin>>prob[i];
			prob[i]/=100;
		
			cin>>first[i];
			cin>>second[i];
		}
		ispresent.clear();
		dfs(prob,first,second);
		cout<<totalprob<<endl;
		
	}
}
