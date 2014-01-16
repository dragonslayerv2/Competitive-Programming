#include<iostream>
#include<stack>
#include<list>
#include<deque>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

inline bool inRange(pair<int,int> range,int pos)
{
	if(pos>=range.first&&pos<=range.second)
		return true;
	else
		return false;
}

void fillrange(vector<int> &array , list<pair<int,int> > &range,list<long long>& range_sum)
{
	vector<long long> cumulative(array.size());
	for(int i=1;i<array.size();i++)
	{
		cumulative[i]=cumulative[i-1]+array[i];
	}

	for(list<pair<int,int> >:: iterator i=range.begin();i!=range.end();i++)
	{
		range_sum.push_back(cumulative[i->second]-cumulative[i->first-1]);
	}
}
inline void emptystack(stack<list<pair<int,int> >::iterator> &delete_stack1, stack<list<long long>::iterator> &delete_stack2,list<pair<int,int> > &range,list<long long> &range_sum)
{
	while(!delete_stack1.empty())
	{
		range.erase(delete_stack1.top());
		range_sum.erase(delete_stack2.top());
		delete_stack1.pop();
		delete_stack2.pop();
	}
}


int main()
{
	int n;
	cin>>n;
	
	int m;
	cin>>m;
	vector<int> array;
	array.resize(n+1);
	for(int i=1;i<=n;i++)
		cin>>array[i];
	

	
	list<pair<int,int> > range;
	//range.resize(m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		range.push_back(make_pair(a,b));
	} 
//	sort(range.begin(),range.end());
	
	list<long long> range_sum;
	fillrange(array,range,range_sum);

/*	for(auto i=range_sum.begin();i!=range_sum.end();i++)
	{
		cout<<*i;
	}*/
	int k;
	cin>>k;
	int ans=0;
	stack<list<pair<int,int> >::iterator> delete_stack1;
	stack<list<long long>::iterator> delete_stack2;
	while(k--)
	{
		int pos;
		cin>>pos;
		pos=pos+ans;
		//cout<<"Checking for "<<pos<<endl;
		if(array[pos]!=0)
		{
			array[pos]--;
			list<pair<int,int> >::iterator i=range.begin();
			list<long long>::iterator j=range_sum.begin(); 
			for(; i != range.end() ; i++,j++)
			{		
			//	cout<<"checking for range"<<i->first<<" "<<i->second<<endl;
				if(inRange(*i,pos))
				{		
			//		cout<<"Range sum = "<<*j<<endl;
					(*j)--;
					if((*j)==0)
					{
			//			cout<<"Pushing them to delete stack";
						delete_stack1.push(i);
						delete_stack2.push(j);
						ans++;
					}
						
				}	
			}
		}
		emptystack(delete_stack1,delete_stack2,range,range_sum);
		cout<<ans<<endl;	
	}
}

