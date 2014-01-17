#include<iostream>
#include<stack>
#include<map>
#include<vector>
#include<list>
using namespace std;

//#define DEBUG

typedef map<long long, pair<long long,long long> > MAP;
int main()
{
	#ifdef DEBUG
		freopen("test.txt","r",stdin);
	#endif

	int q;
	cin>>q;
	MAP array;
	long long pos=1;
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			long long number;
			cin>>number;
			array[pos]=make_pair(number,0);
			pos++;
		}
		else
		{
			long long l,c;
			cin>>l>>c;
			if(pos<=100000)
			{
				for(int i=0;i<c;i++)
				{
					for(int j=1;j<=l;j++)
					{
						array[pos]=array[j];		
						pos++;
					}
				}
			}
			else
			{
				array[pos]=make_pair(l,c);
				pos+=l*c;
			}
		}
	}
	
	cin>>q;
	map<long long, long long> solution;
	while(q--)
	{
		long long n;
		cin>>n;
		
		stack<long long> solution_stack;
		long long ans;
		while(1)
		{
			if(solution[n]!=0)
			{
				ans=solution[n];
				while(!solution_stack.empty())
				{
					long long P=solution_stack.top(); // optimisation for O(1) amortised time
					{
						if(P<=100000)
							solution[P]=ans;
					}
					solution_stack.pop();
				}
				break;
			}
				
			solution_stack.push(n);
			MAP::iterator i=array.find(n);
			if(i==array.end())
			{
				array[n]=make_pair(0,0);
				i=array.find(n);
				i--;
				array.erase(n);
			}
			if(i->second.second==0)
			{
				ans=i->second.first;
				while(!solution_stack.empty())
				{
					long long P=solution_stack.top(); // optimisation for O(1) amortised time
					{
						if(P<=100000)
							solution[P]=ans;
					}
					solution_stack.pop();
				}
				
				break;
			}
			else
			{
				long long pos=n-i->first;
				pos=pos%i->second.first;
				n=pos+1;
			}
		}
		cout<<ans<<" ";
	}
}
