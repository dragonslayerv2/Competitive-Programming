<pre>#include&lt;iostream&gt;
#include&lt;map&gt;
using namespace std;

int main()
{
	int n;
	cin&gt;&gt;n;
	map&lt;int,int&gt; smaller;
	
	int a;
	cin&gt;&gt;a;
	smaller[a]++;
	for(int i=0;i&lt;n-1;i++)
	{
		
		int a;
		cin&gt;&gt;a;
		
		if(!smaller[a])
		{
			map&lt;int,int&gt;::iterator x=smaller.find(a);
			if(x!=smaller.begin())
				x--;
			if(x-&gt;second)
				x-&gt;second--;
			if(x-&gt;second==0)
				smaller.erase(x);
			smaller[a]++;
		}
	}
	cout&lt;&lt;smaller.size();
}</pre>