#include<iostream>
#include<vector>
#include<list>
using namespace std;

int n;
vector<list<int> > domain;
vector<int> series;

bool solve(int pos=0)
{
	if(pos==n)
	{
		vector<int> count(series.size());
		for(int i=0;i<series.size();i++)
			count[series[i]]++;
		bool isOK=true;
		for(int i=0;i<series.size();i++)
			if(count[i]!=series[i])
			{
				isOK=false;
				break;
			}
		return isOK;
	}
	for(list<int>::iterator i=domain[pos].begin();i!=domain[pos].end();i++)
	{
		series[pos]=*i;
		if(solve(pos+1))	return true;
	}
	return false;
}

int main(int argc,char *argv[])
{
	if(argc==2)
	{
		
		sscanf(argv[1],"%d",&n);
		
		//generate domain
		
		domain.resize(n);
		
		for(int i=1;i<n-1;i++)
			domain[0].push_back(i);
			
		for(int i=1;i<n-1;i++)
			for(int j=0;j<=n/i&&j<n-1;j++)
				domain[i].push_back(j);
		
		domain[n-1].push_back(0);
		
		series.resize(n);
		
		cout<<n<<endl;
		if(!solve())
			cout<<"No such series\n";
		else
			for(int i=0;i<series.size();i++)
				cout<<series[i]<<" ";
	}
	else
		cout<<"Usage: magic_series [size_to solve]\nExample: magic_series 5\n";
}
