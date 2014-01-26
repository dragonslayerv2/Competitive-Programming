<pre>#include&lt;stdio.h&gt;
#include&lt;cmath&gt;
#include&lt;queue&gt;
#include&lt;list&gt;
#include&lt;vector&gt;
#include&lt;map&gt;
using namespace std;

vector&lt;bool&gt; istraversed;
void dfs(vector&lt;list&lt;pair&lt;int,long long&gt; &gt; &gt; &amp;graph,vector&lt;int&gt; &amp;level,vector&lt;int&gt; &amp;position,vector&lt;pair&lt;int,long long&gt; &gt; &amp;rmqarray,int source=0)
{
	
	if(!istraversed[source])
	{
		istraversed[source]=true;
		position[source]=rmqarray.size();
		rmqarray.push_back(make_pair(level[source],source));
		for(list&lt;pair&lt;int,long long&gt; &gt;::iterator i=graph[source].begin();i!=graph[source].end();i++)
		{
			if(!istraversed[i-&gt;first])
			{
				dfs(graph,level,position,rmqarray,i-&gt;first);	
				rmqarray.push_back(make_pair(level[source],source));	
			}
		}
	}
}
template&lt;class T&gt; class rmq
{
	private:
		vector&lt;vector&lt;T&gt; &gt; RMQ;
	public:
		rmq(vector&lt;T&gt; &amp;arr)
		{
	//------------------------------------------------
			int n=arr.size();
			RMQ.resize(n);
			int len=5+ceil(log(arr.size()));
			for(int i=0;i&lt;n;i++)
			{
				RMQ[i].resize(len);
			}
			
			
	//----------------------------------------------
			for(int i=0;i&lt;n;i++)
			RMQ[i][0]=arr[i];
	
			for(int j=1,p=2;p&lt;=n;j++,p*=2)
			{
				for(int i=0;i+p&lt;=n;i++)
				RMQ[i][j]=min(RMQ[i][j-1],RMQ[i+p/2][j-1]);
			}
		}
		
		T query(int i,int j)
		{
			
			int gap=j-i+1;
			int p=-1;
			int po=1;
	
			while(gap) // calculates 2^(floor(logk)) and floor(logk)
			{
				gap=gap/2;
				p++;
				po&lt;&lt;=1;
			}
			po/=2;
			
			return min(RMQ[i][p],RMQ[j-po+1][p]);
		}
};

int main()
{
	
	while(1)
	{
		int n;
		scanf(&quot;%d&quot;,&amp;n);
		//cin&gt;&gt;n;
		
		if(n==0)
			break;
		
		vector&lt;list&lt;pair&lt;int,long long&gt; &gt; &gt; graph(n);
		
		for(int i=1;i&lt;n;i++)
		{
			int b,w;
			scanf(&quot;%d %d&quot;,&amp;b,&amp;w);
			//cin&gt;&gt;b&gt;&gt;w;
			graph[i].push_back(make_pair(b,w));
			graph[b].push_back(make_pair(i,w));
		}
	
		vector&lt;int&gt; level(n,-1);
		vector&lt;long long &gt; distances(n,0);
		
		//--bfs-------
		queue&lt;int&gt; Q;
		level[0]=0;
		distances[0]=0;
		Q.push(0);
		
		
		while(!Q.empty())
		{
			int current=Q.front();
			Q.pop();
			for(list&lt;pair&lt;int,long long&gt; &gt;::iterator i=graph[current].begin();i!=graph[current].end();i++)
			{
				if(level[i-&gt;first]==-1)
				{
					level[i-&gt;first]=level[current]+1;
					distances[i-&gt;first]=distances[current]+i-&gt;second;
					Q.push(i-&gt;first);
				}
			}
		}
		
		//----------------------------------------------------------------------
		vector&lt;int&gt; position(n);
		vector&lt;pair&lt;int,long long&gt; &gt; rmqarray;
		istraversed.clear();
		istraversed.resize(n);
	
		dfs(graph,level,position,rmqarray);
		
				
		rmq&lt;pair&lt;int,long long&gt; &gt;  RMQ(rmqarray);
		
		
		int q;
		scanf(&quot;%d&quot;,&amp;q);
		//cin&gt;&gt;q;
		while(q--)
		{
			int a,b;
			scanf(&quot;%d %d&quot;,&amp;a,&amp;b);
			//cin&gt;&gt;a&gt;&gt;b;
			pair&lt;int,int&gt; LCA=RMQ.query(min(position[a],position[b]),max(position[a],position[b]));
			printf(&quot;%lld &quot;,distances[a]+distances[b]-2*distances[LCA.second]);
		}
		printf(&quot;\n&quot;);	
	}
}</pre>