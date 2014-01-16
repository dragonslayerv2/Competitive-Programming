#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
using namespace std;

map<int,bool> hashmap;

template<class A,class B> double Prob(A data,B probability,int i=0);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<pair<int,int> > data;
		vector<double> probability;
		int n;
		cin>>n;
		while(n--)
		{
			int a,b;
			double p;
			cin>>p;
			cin>>a>>b;
			probability.push_back(p/100);
			data.push_back(make_pair(a,b));
		}
		cout<<fixed<<setprecision(6)<<Prob(data,probability)<<endl;
	}
}

template<class A,class B> double Prob(A data,B probability,int i=0)
{
	if(i==data.size())
		return 1;
	double p=0;
	if(hashmap[data[i].first]==false)
	{
		hashmap[data[i].first]=true;
		p+=probability[i]*Prob(data,probability,i+1);
		hashmap[data[i].first]=false;
	}
	if(hashmap[data[i].second]==false)
	{
		hashmap[data[i].second]=true;
		p+=(1-probability[i])*Prob(data,probability,i+1);
		hashmap[data[i].second]=false;
	}
	return p;
}
