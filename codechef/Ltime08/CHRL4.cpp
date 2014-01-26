<pre>#include&lt;iostream&gt;
#include&lt;queue&gt;
#include&lt;map&gt;
#include&lt;limits&gt;
#include&lt;cmath&gt;
#include&lt;vector&gt;
using namespace std;

#define MOD 1000000007

struct comparator{
    bool operator() ( pair&lt;double,int&gt; i, pair&lt;double,int&gt; j){
        if ( i &lt; j )
            return false;
        else
            return true;
    }
 
};


int main()
{
	int n,k;
	cin&gt;&gt;n&gt;&gt;k;
	vector&lt;long long&gt; a(n);
	for(int i=0;i&lt;n;i++)
		cin&gt;&gt;a[i];
	
	vector&lt;pair&lt;double,long long &gt; &gt; solution(n);
	solution[n-1]=make_pair(log(a[n-1]),a[n-1]);
	priority_queue&lt;pair&lt;double,int&gt; , std::vector&lt;pair&lt;double,int&gt; &gt;, comparator&gt; minHeap;
	
	minHeap.push(make_pair(solution[n-1].first,n-1));
	
	for(int i=n-2;i&gt;=(n-1-k);i--)
	{
		solution[i]=make_pair(solution[n-1].first+log(a[i]),(solution[n-1].second*a[i])%MOD);
		minHeap.push(make_pair(solution[i].first,i));
	}
	for(int i=n-3;i&gt;=0;i--)
	{
		while(minHeap.size()&amp;&amp;minHeap.top().second&gt;i+k)
 			minHeap.pop();
		int pos=minHeap.top().second;
		solution[i]=make_pair(solution[pos].first+log(a[i]),(solution[pos].second*a[i])%MOD);
		minHeap.push(make_pair(solution[i].first,i));
	}
	cout&lt;&lt;solution[0].second;
}</pre>