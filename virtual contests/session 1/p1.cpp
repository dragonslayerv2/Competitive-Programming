// RRANGE SPOJ
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstdio>
using namespace std;

//#define DEBUG

struct query
{
	int first,second;
	int pos;
};

bool operator <(const query &Q1,const query &Q2)
{
	return Q1.second<Q2.second;
}
//------------------------------------------------------------------------------
template<class T> class segment_tree
{
	public:
		typedef T value_type;
		
	private:
		vector<value_type> _T;
		vector<value_type> _lazy;
		size_t _sz;
		
		bool _in_range(size_t query_left,size_t query_right,size_t node_left,size_t node_right) const
		{
			if(node_left > node_right || node_left > query_right || node_right < query_left) // Current segment is not within range [i, j]
				return false;
			return true;
		}
		void _build_tree(const vector<value_type> &A,int i,int j, size_t node)
		{
			if(i==j)
				_T[node]=A[i-1];
			else
			{
				_build_tree(A,i,(i+j)/2,node*2);
				_build_tree(A,(i+j)/2+1,j,node*2+1);
				_T[node]=_T[node*2]+_T[node*2+1];
			}
		}
		
		value_type _query(size_t query_left,size_t query_right,size_t node_left, size_t node_right, size_t node)
		{
			if(node_left>=query_left&&node_right<=query_right)
				return _T[node];
			else
			{
				size_t left_node_left=node_left;
				size_t left_node_right=(node_left+node_right)/2;
				size_t right_node_left=(node_left+node_right)/2+1;
				size_t right_node_right=node_right;

				bool left=_in_range(query_left,query_right,left_node_left,left_node_right);
				bool right=_in_range(query_left,query_right,right_node_left,right_node_right);
				
				value_type result_left;
				if(left)
					result_left=_query(query_left,query_right,node_left,(node_left+node_right)/2,node*2);
				
				value_type result_right;
				if(right)
					result_right=_query(query_left,query_right,(node_left+node_right)/2+1,node_right,node*2+1);
				
				
				if(left&&right)
					return result_left+result_right;
				else if(left)
					return result_left;
				else 
					return result_right;
			}
		}
		
		void _update(size_t query_left,size_t query_right,size_t range_left,size_t range_right,size_t node,value_type value)
		{			
			if(!_in_range(query_left,query_right,range_left,range_right))
				return;
			
			if(range_left==range_right)
				_T[node]=value;
			else
			{
				_update(query_left,query_right,range_left,(range_left+range_right)/2,node*2,value);
				_update(query_left,query_right,(range_left+range_right)/2+1,range_right,node*2+1,value);
				
				_T[node]=_T[node*2]+_T[node*2+1];	
			}
		}
	public:
		segment_tree()
		{
			_sz=0;
		}
		
		segment_tree(size_t size)
		{
			assign(size);
		}
		
		segment_tree(const vector<value_type> &A)
		{
			clear();
			assign(A);
		}
		
		void assign(size_t size,value_type initial=value_type())
		{
			clear();
			_sz=size;
			_T.resize(4*size,initial);
		}
		
		void assign(const vector<value_type> &A) // assumes vector to be 0 indexed
		{
			assign(A.size());
			build_tree(A,1,A.size(),1);	
		}
		
		void update(size_t i,size_t j,value_type value)
		{
			_update(i,j,1,_sz,1,value);
		}
		
		value_type query (size_t i,size_t j)
		{
			return _query(i,j,1,_sz,1);
		}
		
		void clear()
		{
			_sz=0;
			_T.clear();
		}
		
		~segment_tree()
		{
			clear();
		}
};
//------------------------------------------------------------------------------
int main()
{
	#ifdef DEBUG
		freopen("test1.txt","r",stdin);
	#endif
	const int MAX=1000005;
	char *brackets=new char[MAX];
	
	cin>>(brackets+1);
	int m;
	cin>>m;
	
	vector<query> Q(m);
	for(int i=0;i<m;i++)
	{
		cin>>Q[i].first;
		cin>>Q[i].second;
		Q[i].pos=i;
	}
	
	sort(Q.begin(),Q.end());	

	int current=1;
	
	stack<int> S;
	segment_tree<int> ST(MAX);	
	vector<int> solution(Q.size());
	
	for(int i=0;i<Q.size();i++)
	{
		while(current<=Q[i].second&&brackets[current])
		{
			if(brackets[current]=='(')
			{
				S.push(current);
			}
			else if(!S.empty()&&brackets[current]==')')
			{
				ST.update(S.top(),S.top(),1);
				S.pop();
			}
			current++;	
		}
		solution[Q[i].pos]=ST.query(Q[i].first,Q[i].second)*2;
	
	}
	
	for(int i=0;i<solution.size();i++)
	{
		cout<<solution[i]<<endl;
	}
}
