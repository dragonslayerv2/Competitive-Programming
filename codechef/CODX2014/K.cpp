<pre>#include&lt;iostream&gt;
using namespace std;


int main()
{
	int t;
	cin&gt;&gt;t;
	while(t--)
	{
		long long a,b;
		cin&gt;&gt;a&gt;&gt;b;
		long long n=b-a+1;
		int first=n;
		int second=n-1;
		cout&lt;&lt;(n*(n-1))/2&lt;&lt;endl;
	}
}</pre>