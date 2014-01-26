<pre>#include&lt;iostream&gt;
#include&lt;vector&gt;
#include&lt;limits&gt;
using namespace std;

int main()
{
	int n;
	cin&gt;&gt;n;
	n+=2;
	
	vector&lt;pair&lt;int,int&gt; &gt; points(n);
	points[0].first=points[0].second=0;
	
	for(int i=1;i&lt;n;i++)
		cin&gt;&gt;points[i].first&gt;&gt;points[i].second;
	
	vector&lt;vector&lt;long long&gt; &gt; graph(n,vector&lt;long long&gt;(n));
	
	for(int i=0;i&lt;graph.size();i++)
		for(int j=0;j&lt;graph.size();j++)
			graph[i][j]=(points[i].first-points[j].first)*(points[i].first-points[j].first)+(points[i].second-points[j].second)*(points[i].second-points[j].second);
	
	vector&lt;long long&gt; distances(n,numeric_limits&lt;long long&gt;::max());
	vector&lt;long long&gt; used(n,false);
	
	distances[0]=0;

	
	for(int i=0;i&lt;n;i++)
	{
		int minpos=-1;
		long long minvalue=numeric_limits&lt;long long&gt;::max();	
		for(int j=0;j&lt;n;j++)
		{
			if(!used[j])
			{		
				if(minvalue&gt;distances[j])
				{
				
					minvalue=distances[j];
					minpos=j;
				}
			}				
		}
		if(minpos==-1)
			break;
		used[minpos]=true;
		for(int j=0;j&lt;n;j++)
		{
			if(!used[j])
				distances[j]=min(distances[j],distances[minpos]+graph[minpos][j]);
		}
	}
	cout&lt;&lt;distances[n-1];
}</pre>