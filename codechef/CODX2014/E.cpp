/*
	Name: 
	Copyright: 
	Author: 
	Date: 28/01/14 19:33
	Description: web.cecs.pdx.edu/~mperkows/CLASS.../0090.Simulated-Annealing.ppt?
*/

#include<stdio.h>
#include<cmath>
#include<vector>
using namespace std;

double dist(vector<pair<double,double> > &points,pair<double,double> answer)
{
	double ans=0;
	for(int i=0;i<points.size();i++)
		ans+=sqrt((points[i].first-answer.first)*(points[i].first-answer.first)+(points[i].second-answer.second)*(points[i].second-answer.second));
	return ans;
}
pair<double,double> getmedian(vector<pair<double,double> > &points)
{
	double esp=0.001;
	double step=100.0;
	int gradientx[]={-1,0 ,1,0};
	int gradienty[]={0 ,1,0,-1};
	pair<double,double> ans=make_pair(0.0,0.0);
	
	for(int i=0;i<points.size();i++)
	{
		ans.first+=points[i].first;
		ans.second+=points[i].second;
	}
	ans.first /=points.size();
	ans.second/=points.size();
	
	double lastsolution=dist(points,ans);
	while(step>esp)
	{
		bool done=false;
		for(int i=0;i<4;i++)
		{
			pair<double,double> newanswer=make_pair(ans.first+step*gradientx[i],ans.second+step*gradienty[i]);
			double newsolution=dist(points,newanswer);
			if(newsolution<lastsolution)
			{
				lastsolution=newsolution;
				ans=newanswer;
				done=true;
				break;
			}
		}	
		if(!done)
			step/=2;
	}
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<pair<double,double> > points(n);
	for(int i=0;i<n;i++) 
		scanf("%lf %lf",&points[i].first,&points[i].second);
	printf("%.2lf\n",dist(points,getmedian(points)));
}
