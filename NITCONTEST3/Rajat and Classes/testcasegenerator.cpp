#include<iostream>
#include<set>
#include<time.h>
#include<cstdlib>
using namespace std;

int main()
{
	freopen("test2.txt","w",stdout);
	srand(time(NULL));
	int n=100;
	int c=100;
	cout<<n<<" "<<c<<endl;
	
	set<pair<int,int> > S;
	while(c--)
	{
		int a=1+rand()%n;
		int b=1+rand()%n;
		while(a==b||S.find(make_pair(a,b))!=S.end())
		{
			a=1+rand()%n;
			b=1+rand()%n;
		}
		S.insert(make_pair(a,b));
		S.insert(make_pair(b,a));
		
		cout<<a<<" "<<b<<endl;		
	}
}
