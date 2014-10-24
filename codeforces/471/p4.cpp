#include<iostream>
#include<vector>
using namespace std;


void computePiFunction(vector<int>& p,vector<int>& Pi)
{
		int m=p.size();
		Pi[0]=-1;
		int k=-1;
		for(int i=1;i<m;i++)
		{
			while(k>=0&&p[k+1]!=p[i])
				{k=Pi[k];}
			if(p[k+1]==p[i])
				k++;
			Pi[i]=k;	
		}
}

int matcher(vector<int> &P,vector<int> &T,vector<int> &Pi)
{
	int m=P.size();
	int q=-1;
	int count=0;
	for(int i=0;i<T.size();i++)
	{
		while(q>=0&&P[q+1]!=T[i])
			q=Pi[q];
		if(P[q+1]==T[i])	
			q++;
		if(q==m-1)
		{
			count++;
			q=Pi[q];
		}
	}
	return count;
}

int main(){
	
	//freopen("test.txt","r",stdin);
	int n;
	int p;
	cin>>n>>p;
	vector<int> array;
	vector<int> pattern;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		array.push_back(x);
			
	}
	
	for(int i=0;i<p;i++)
	{
		int x;
		cin>>x;
			pattern.push_back(x);
	}
	if(pattern.size()==1)
		cout<<array.size();
	else
	{
		vector<int> P;
		vector<int> T;
		
		for(int i=1;i<pattern.size();i++){
			P.push_back(pattern[i]-pattern[i-1]);
		}
		for(int i=1;i<array.size();i++){
			T.push_back(array[i]-array[i-1]);
		}
		vector<int> Pi(P.size());
		computePiFunction(P,Pi);
		cout<<matcher(P,T,Pi);;
	}
	
}
