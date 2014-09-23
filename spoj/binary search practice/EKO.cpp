#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findHeight(int low,int high,int m,vector<int> &heights){
	while(low<high){
		int mid=(low+high)/2;
		int mCopy=m;
		bool isPossible=false;
		for(int i=0;i<heights.size();i++)
		{
			mCopy-=max(0,heights[i]-mid);
			if(mCopy<=0)
			{
				isPossible=true;
				break;
			}
		}
		if(isPossible)
			low=mid+1;
		else
			high=mid;
	}
	return low-1;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> heights(n);
	for(int i=0;i<n;i++)
		scanf("%d",&heights[i]);
	sort(heights.begin(),heights.end());
	cout<<findHeight(0,heights.back(),m,heights);
}
