/*
	Name: KD Trees
	Copyright: 
	Author: Shobhit Saxena
	Date: 07/12/13 11:24
	Description: Assuming no two points share the same dimensions...
*/

#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

//----------------------------------- median finding algorithm-----------------
template<class iterator,class compare>iterator random_partition(iterator begin, iterator end,const compare &cmp)
{
	iterator pivot=begin+((rand())%(end-begin));

	swap(*pivot,*(end-1));
	pivot=end-1;
	iterator k=begin;
	while(begin!=end)
	{
		if(cmp(*begin,*pivot))
		{
			swap(*begin,*k);
			k++;
		}
		begin++;
	}
	
	swap(*pivot,*k);
	return k;
}

template<class iterator,class compare> iterator select(iterator begin,iterator position,iterator end,const compare &cmp)
{
	iterator i=random_partition(begin,end,cmp);
	
	if(i==position)
		return i;
	else if(i<position)
		return select(i+1,position,end,cmp);
	else
		return select(begin,position,i,cmp);
}

//------------------------------------------------------------------------------

template<size_t K>class kdtree
{
	private:
		struct node
		{
			bool is_leaf;
			node *left, *right;
			int value;
			int point[K];
		};
		node *root;
		
		//--------------- compare class for dimension matching ------------------
		class _compare
		{
			private:
				size_t _dimension;
			public:
				_compare(size_t D)
				{
					_dimension=D;
				}
				template<class T> bool operator() (const T& a,const T &b) const
				{
					return a[_dimension]<b[_dimension];
				}			
		};
		//----------------------------------------------------------------------
		template<class iterator> node* _build_tree(iterator begin,iterator end,size_t depth=0)
		{
			if(begin==end-1)
			{
				
				node *newleaf=new node;
				newleaf->is_leaf=true;
				newleaf->left=newleaf->right=NULL;
				for(size_t k=0;k<K;k++)
					newleaf->point[k]=(*begin)[k];

				return newleaf;
			}
			else
			{
				node* internal_node=new node;
				internal_node->is_leaf=false;
				iterator median=select(begin,begin+(end-begin)/2,end,_compare(depth%K));
				
				internal_node->left=_build_tree(begin,median,depth+1);
				internal_node->right=_build_tree(median,end,depth+1);
				internal_node->value=(*median)[depth%K];
				
				return internal_node;
			}
		}
		
		void _delete(node *root)
		{
			if(root==NULL)
				return;
			else
			{
				_delete(root->left);
				_delete(root->right);
				delete root;
			}
		}
		
		template<class point> bool _find(const point &x,node * root,size_t depth=0)
		{
			if(root->is_leaf)
			{
				for(int i=0;i<K;i++)
					if(x[i]!=root->point[i]) return false;
				return true;
			}
			else
			{
				if(x[(depth%K)]<root->point[depth%K])
					return _find(x,root->left,depth+1);
				else 
					return _find(x,root->right,depth+1);
			}
		}
	public:
		kdtree()
		{
			root=NULL;
		}
		template<class iterator> kdtree(iterator begin,iterator end)	
		{
			assign(begin,end);
		}
		
		template<class iterator> void assign(iterator begin,iterator end)	
		{
			root=_build_tree(begin,end);
		}
		template<class point> bool find(const point x)
		{
			return _find(x,root);
		}
		
		void clear()
		{
			_delete(root);
			root=NULL;
		}
		~kdtree()
		{
			clear();
		}
		
};
int main()
{
	int n;
	cin>>n;
	vector<vector<int> > points;
	for(int i=0;i<n;i++)
		cin>>points[i][0]>>points[i][1];
	kdtree<2> tree;
	tree.assign(points.begin(),points.end());
	
	int q;
	cin>>q;
	while(q--)
	{
		vector<int>  point(2);		
		cin>>point[0]>>point[1];
		cout<<tree.find(point)<<endl;
	}
}
