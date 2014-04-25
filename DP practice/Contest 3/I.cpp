#include<iostream>
#include<limits>
#include<climits>
#include<vector>
#include<cmath>
using namespace std;

inline double dist(pair<int,int> a,pair<int,int> b)
{
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

void printCable(pair<int,int> a,pair<int,int> b)
{
	
	cout<<"Cable requirement to connect ("<<a.first<<","<<a.second<<") to ("<<b.first<<","<<b.second<<") is ";
	cout.setf(ios::fixed);
	cout.precision(2);
	cout<<16+dist(a,b)<<" feet."<<endl;
}
int main()
{
//	freopen("testI.txt","r",stdin);
	int t=0;
	while(1)
	{
		
		int n;
		cin>>n;
		if(n==0)
			break;
		cout<<"**********************************************************"<<endl;
		t++;
		cout<<"Network #"<<t<<endl;
		vector<vector<double> > DP(1<<n,vector<double>(n));
		
		vector<pair<int,int> > points(n);
		for(int i=0;i<n;i++)
			cin>>points[i].first>>points[i].second;
		
		for(int i=(1<<n)-2;i>=0;i--)
			for(int j=0;j<n;j++)
			{
				DP[i][j]=INT_MAX;
				for(int k=0;k<n;k++)
				{
					if((i&(1<<k))==0)
						DP[i][j]=min(DP[i][j],16+dist(points[j],points[k])+DP[i|(1<<k)][k]);
				}
			}
		
		double MIN=numeric_limits<double>::max();
		int start;
		for(int i=0;i<n;i++)
			if(MIN>DP[1<<i][i])
			{
				MIN=DP[1<<i][i];
				start=i;
			}
		int S=(1<<start);
		
		int last;
		double sum=0;
		while(S!=((1<<n)-1))
		{
			double MIN=INT_MAX;
			for(int k=0;k<n;k++)
			{
				if((S&(1<<k))==0)
				{			
					if((16+dist(points[start],points[k])+DP[S|(1<<k)][k])<MIN)
					{
						MIN=(16+dist(points[start],points[k])+DP[S|(1<<k)][k]);
						last=k;
					}
				}
			}
			printCable(points[start],points[last]);
			sum+=16+dist(points[start],points[last]);
			
			start=last;
			S|=(1<<last);
			
		}
		cout.setf(ios::fixed);
		cout.precision(2);
		cout<<"Number of feet of cable required is "<<sum<<"."<<endl;
	}
}
