#include<iostream>
#include<vector>
#include<stack>
using namespace std;



int maxHistogramArea(vector<int> &histogram)
{
	stack<int> S;
	vector<int> L(histogram.size());
	vector<int> R(histogram.size());
	
	for(int i=0;i<histogram.size();i++)
	{
		
		while(!S.empty())
		{
			if(histogram[S.top()]>=histogram[i])
				S.pop();
			else
				break;
		}
		
		if(S.empty())
			L[i]=-1;
		else
			L[i]=S.top();
		S.push(i);
	}
	while(!S.empty())
		S.pop();
		
	for(int i=histogram.size()-1;i>=0;i--)
	{
		while(!S.empty())
		{
			if(histogram[S.top()]>=histogram[i])
				S.pop();
			else
				break;
		}
		
		if(S.empty())
			R[i]=histogram.size();
		else
			R[i]=S.top();
		S.push(i);
	}
	
	int maxarea=0;
	for(int i=0;i<histogram.size();i++)
	{
		maxarea=max(maxarea,histogram[i]*(R[i]-L[i]-1));
	}
	return maxarea;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		vector<vector<int> > histogram(n+2,vector<int>(m));
		int max_area=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<m;j++)
			{
				char a;
				cin>>a;
				if(a=='F')
					histogram[i][j]=histogram[i-1][j]+1;
			}
			#ifdef DEBUG
			for(int j=0;j<m;j++)
				cout<<histogram[i][j];
			cout<<endl;
			#endif
			max_area=max(max_area,maxHistogramArea(histogram[i]));
		}
		cout<<max_area*3<<endl;
	}
}
