<pre>#include&lt;iostream&gt;
using namespace std;


int main()
{
	string a;
	cin&gt;&gt;a;
	
	int c=0;
	int h=0;
	int e=0;
	int f=0;
	
	int count=0;
	while(c!=a.size()&amp;&amp;h!=a.size()&amp;&amp;e!=a.size()&amp;&amp;f!=a.size())
	{
		while(a[c]!='C'&amp;&amp;c!=a.size())
			c++;
		if(c&gt;=a.size())
			break;
		c++;
		
		while((a[h]!='H'||h&lt;c)&amp;&amp;h!=a.size())
			h++;
		if(h&gt;=a.size())
			break;
		h++;
		
		while((a[e]!='E'||e&lt;h)&amp;&amp;e!=a.size())
			e++;
		if(e&gt;=a.size())
			break;
		e++;
		
		while((a[f]!='F'||f&lt;e)&amp;&amp;f!=a.size())
			f++;
		if(f&gt;=a.size())
			break;
		count++;
		f++;
	}
	cout&lt;&lt;count;
}</pre>