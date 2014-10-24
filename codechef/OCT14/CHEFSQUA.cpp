#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef pair<int,int> point;

#include<cstdio>
int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<point > points(n);
	set<point > pointSet;
	for(int i=0;i<n;i++)
	{
		cin>>points[i].first>>points[i].second;
		pointSet.insert(points[i]);
	}
	
	int maximum=((n==0)?4:3);
	for(int i=0;i<points.size();i++)
		for(int j=i+1;j<points.size();j++){
			
			for(int k=0;k<2;k++){
					int currentAnswer=2;
					int changeY=points[i].first-points[j].first;
					int changeX=points[i].second-points[j].second;
					
					if(k)
						changeX*=-1;
					else
						changeY*=-1;
					
					point newPoint1=make_pair(points[i].first+changeX,points[i].second+changeY);
					point newPoint2=make_pair(points[j].first+changeX,points[j].second+changeY);
					if(pointSet.find(newPoint1)!=pointSet.end()&&newPoint1!=points[j]){
						//cout<<"Found Point "<<newPoint1.first<<" "<<newPoint1.second<<endl;
						currentAnswer--;	
					}
					
	
					if(pointSet.find(newPoint2)!=pointSet.end()&&newPoint2!=points[i]){
						//cout<<"Found Point "<<newPoint1.first<<" "<<newPoint1.second<<endl;
						currentAnswer--;
					}
						
					maximum=min(currentAnswer,maximum);
				}
		}
	cout<<maximum;
}
