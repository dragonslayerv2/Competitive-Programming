<pre>#include&lt;iostream&gt;
using namespace std;

int getbase(int a)
{
	int base=0;
	while(a)
	{
		base=max(base,a%10);
		a/=10;
	}
	return base+1;
}

int convert(int number,int base)
{
	int current=1;
	int output=0;
	while(number)
	{
		output+=(number%10)*current;
		number/=10;
		current*=base;
	}
	return output;
}
int main()
{
	int t;
	cin&gt;&gt;t;
	while(t--)
	{
		int a,b;
		cin&gt;&gt;a&gt;&gt;b;
		int baseA=getbase(a);
		int baseB=getbase(b);
		cout&lt;&lt;convert(a,baseA)+convert(b,baseB)&lt;&lt;endl;
	}
}</pre>