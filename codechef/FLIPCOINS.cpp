#include<stdio.h>
#include<vector>
using namespace std;


//#define DEBUG

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
			#ifdef DEBUG
				cout<<"IN RANGE" <<node_left<<" "<<node_right<<endl;
			#endif
			
			if(_lazy[node])
			{
				_T[node]=(node_right-node_left+1)-_T[node];
				if(node_left!=node_right)
				{
					_lazy[node*2]^=1;
					_lazy[node*2+1]^=1;	
				}	
				_lazy[node]=0;
			}
			#ifdef DEBUG
			cout<<"NODE VALUE = "<<_T[node]<<endl;
			#endif
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
		
		
		void _update(size_t query_left,size_t query_right,size_t range_left,size_t range_right,size_t node)
		{
			#ifdef DEBUG
			cout<<"RANGE "<<range_left<<" "<<range_right<<endl;
			cout<<"Initial Value "<<_T[node]<<endl; 
			#endif
			if(_lazy[node])
			{
				#ifdef DEBUG
					cout<<"LAZY UPDATE AT THIS PLACE";
					cout<<_lazy[node];
				#endif
				_T[node]=(range_right-range_left+1)-_T[node];
				
				if(range_left!=range_right)
				{
					_lazy[node*2]^=1;
					_lazy[node*2+1]^=1;	
				}
				
				_lazy[node]=0;
			}
			
			if(!_in_range(query_left,query_right,range_left,range_right))
				return;
			else if(range_left>=query_left&&range_right<=query_right)
			{	
				#ifdef DEBUG
					cout<<"LAZY LAZY LAZY "<<endl;
				#endif
				_T[node]=(range_right-range_left+1)-_T[node];
				if(range_left!=range_right)
				{
					_lazy[node*2]^=1;
					_lazy[node*2+1]^=1;
				}
				
			}
			else if(range_left==range_right)
				_T[node]^=1;
			else
			{
				_update(query_left,query_right,range_left,(range_left+range_right)/2,node*2);
				_update(query_left,query_right,(range_left+range_right)/2+1,range_right,node*2+1);
				
				#ifdef DEBUG
					cout<<"UPDATING VALUE OF RANGE "<<range_left<<" "<<range_right;
					cout<<endl;
					cout<<_T[node*2]<<" + "<<_T[node*2+1];
				#endif
				_T[node]=_T[node*2]+_T[node*2+1];	
			}
			#ifdef DEBUG
				cout<<"RANGE "<<range_left<<" "<<range_right<<" ";
				cout<<" NODE VLAUE = "<<_T[node]<<endl;
			#endif
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
			_lazy.resize(4*size);
			_T.resize(4*size,initial);
		}
		
		void assign(const vector<value_type> &A) // assumes vector to be 0 indexed
		{
			assign(A.size());
			build_tree(A,1,A.size(),1);	
		}
		
		
		void update(size_t i,size_t j)
		{
			_update(i,j,1,_sz,1);
		}
		
		value_type query (size_t i,size_t j)
		{
			return _query(i,j,1,_sz,1);
		}
		
		
		
		void clear()
		{
			_sz=0;
			_T.clear();
			_lazy.clear();
		}
		
		~segment_tree()
		{
			clear();
		}
		
		#ifdef DEBUG
		void debug()
		{
			for(int i=0;i<_T.size();i++)
				cout<<_T[i];
			cout<<endl;
		}
		#endif
		
};

int main()
{
	int n,t;
	scanf("%d %d",&n,&t);
	segment_tree<int> coins(n);
	while(t--)
	{
		int command,range1,range2;
		scanf("%d %d %d",&command,&range1,&range2);
		range1++;
		range2++;
		if(command)
			printf("%d\n",coins.query(range1,range2));
		else
			coins.update(range1,range2);
	}
}

