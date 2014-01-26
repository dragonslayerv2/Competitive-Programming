<pre>#include&lt;iostream&gt;
#include&lt;cstdio&gt;
#include&lt;map&gt;
#include&lt;vector&gt;
using namespace std;


map&lt;long long,map&lt;int,long long&gt; &gt; solution;
map&lt;long long,map&lt;int,bool&gt; &gt; exist;
long long solve(vector&lt;pair&lt;long long,long long&gt; &gt; &amp;oranges,long long k,int n)
{
	if(k==0)
		return 0;
	else if(n&lt;0)
		return 0;
	else
	{
		if(!exist[k][n])
		{
			long long ans=solve(oranges,k,n-1);
			if(k-oranges[n].first&gt;=0)
				ans=max(ans,solve(oranges,k-oranges[n].first,n-1)+oranges[n].second);
			exist[k][n]=true;
			solution[k][n]=ans;
		}
		return solution[k][n];
	}
} 
int main()
{
	int t;
	cin&gt;&gt;t;
	while(t--)
	{
		int n;
		long long k;
		cin&gt;&gt;n&gt;&gt;k;
		solution.clear();
		exist.clear();
		vector&lt;pair&lt;long long,long long&gt; &gt; oranges(n);
		for(int i=0;i&lt;n;i++)
			cin&gt;&gt;oranges[i].first&gt;&gt;oranges[i].second;
		cout&lt;&lt;solve(oranges,k,n-1)&lt;&lt;endl;
	}
}</pre>