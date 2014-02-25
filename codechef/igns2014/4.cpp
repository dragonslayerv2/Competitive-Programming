#include<stdio.h>
#include<queue>
#include<map>
#include<limits>
#include<cmath>
#include<vector>
using namespace std;
#include<stdio.h>
#define GETCHAR getchar_unlocked
using namespace std;

inline int readInt()
{
int flag=1;
int n = 0;
char c;
while (1)
{
c=GETCHAR();
if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
else if(flag!=1) break;
}
return n;
}
struct comparator{
    bool operator() ( pair<int,int> i, pair<int,int> j){
        if ( i < j )
            return false;
        else
            return true;
    }
 
};


int main()
{
	int t;
	t=readInt();
	while(t--)
	{
	
	int n,k;
	n=readInt();
	k=readInt();	
	vector<int> a(n);
	for(int i=0;i<n;i++)
		a[i]=readInt();
	vector<int> solution(n);
	solution[n-1]=a[n-1];
	priority_queue<pair<int,int> , std::vector<pair<int,int> >, comparator> minHeap;
	
	minHeap.push(make_pair(solution[n-1],n-1));
	
	for(int i=n-2;i>=(n-1-k);i--)
	{
		solution[i]=solution[n-1]+a[i];
		minHeap.push(make_pair(solution[i],i));
	}
	for(int i=n-3;i>=0;i--)
	{
		while(minHeap.size()&&minHeap.top().second>i+k)
 			minHeap.pop();
		int pos=minHeap.top().second;
		solution[i]=solution[pos]+a[i];
		minHeap.push(make_pair(solution[i],i));
	}
	printf("%d\n",solution[0]);
}
}
