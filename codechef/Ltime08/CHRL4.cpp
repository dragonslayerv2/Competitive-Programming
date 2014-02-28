#include<iostream>
#include<queue>
#include<map>
#include<limits>
#include<cmath>
#include<vector>
using namespace std;

#define MOD 1000000007

struct comparator{
    bool operator() ( pair<double,int> i, pair<double,int> j){
        if ( i < j )
            return false;
        else
            return true;
    }
 
};


int main()
{
	
	int n,k;
	cin>>n>>k;
	vector<long long> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	vector<pair<double,long long > > solution(n);
	solution[n-1]=make_pair(log(a[n-1]),a[n-1]);
	priority_queue<pair<double,int> , std::vector<pair<double,int> >, comparator> minHeap;
	
	minHeap.push(make_pair(solution[n-1].first,n-1));
	
	for(int i=n-2;i>=(n-1-k);i--)
	{
		solution[i]=make_pair(solution[n-1].first+log(a[i]),(solution[n-1].second*a[i])%MOD);
		minHeap.push(make_pair(solution[i].first,i));
	}
	for(int i=n-3;i>=0;i--)
	{
		while(minHeap.size()&&minHeap.top().second>i+k)
 			minHeap.pop();
		int pos=minHeap.top().second;
		solution[i]=make_pair(solution[pos].first+log(a[i]),(solution[pos].second*a[i])%MOD);
		minHeap.push(make_pair(solution[i].first,i));
	}
	cout<<solution[0].second;
}
