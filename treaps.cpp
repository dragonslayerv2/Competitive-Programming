/*
	Name: Treaps
	Copyright: 
	Author: Shobhit Saxena
	Date: 27/11/13 22:46	
	Description: Treaps implementation
				Link: http://www.cs.uiuc.edu/~jeffe/teaching/algorithms/notes/06-treaps.pdf
				
*/
#define DEBUG_LEVEL
#include<iostream>
#include<map>
#include<cstdlib>
using namespace std;

template<class T,class R> class treap
{
	public:
		typedef T key_type;
		typedef typename R::value_type priority_type;
		
	private: 
		struct node
		{
			key_type key;
			priority_type priority;		
			
			node *left,*right,*parent;
		};
	
		node *_root;
		R _random;
		void _rotate_left	(node *x)
		{
			lastchanged=true;
			node *y=x->right;
			x->right=y->left;
			
			if(y->left)
				y->left->parent=x;
			
			y->parent=x->parent;
			if(!y->parent)
				_root=y;
			else if(x==x->parent->left)
				x->parent->left=y;
			else
				x->parent->right=y;
			
			y->left=x;	
			x->parent=y;
		}
		
		void _rotate_right	(node *x) // assumes that y exist..:P
		{
			lastchanged=true;
			node *y=x->left;
			x->left=y->right;
			
			if(y->right)
				y->right->parent=x;
			
			y->parent=x->parent;
			if(!y->parent)
				_root=y;
			else if(x==x->parent->left)
				x->parent->left=y;
			else
				x->parent->right=y;
			
			y->right=x;	
			x->parent=y;
		}
		
		void _recurse_delete(node *root)
		{
			lastchanged=true;
			if(!root)
				return;
			else
			{
				_recurse_delete(root->left);
				_recurse_delete(root->right);
				if(root->parent)
				{
					if(root==root->parent->left)
						root->parent->left=NULL;
					else
						root->parent->right=NULL;
					delete root;
				}
				else
					_root=NULL;
			}
		}
		void _decrease_priority(node *root,priority_type newpriority)
		{
			lastchanged=true;
			root->priority=newpriority;
			node *minimumpriority=NULL;
			while(minimumpriority!=root)
			{
				minimumpriority=root;
				if(root->left&&root->left->priority<minimumpriority->priority)
					minimumpriority=root->left;
				if(root->right&&root->right->priority<minimumpriority->priority)
					minimumpriority=root->right;

				if(minimumpriority==root->left)
				{
					if(root->right)
						_rotate_left(root);
					else
						_rotate_right(root);		
				}

				else if(minimumpriority==root->right)
				{
					if(root->left)
						_rotate_right(root);
					else
						_rotate_left(root);
				}	
			}
		}
		
		void _increase_priority(node *root,priority_type newpriority)
		{
			lastchanged=true;
			root->priority=newpriority;
			while(root->parent&&root->parent->priority>root->priority)
			{
				if(root==root->parent->left)
					_rotate_right(root->parent);
				else
					_rotate_left(root->parent);
			}
		}
		node *_find(key_type KEY) const
		{
			node *current=_root;
			while(current&&current->key!=KEY)
			{
				if(KEY<current->key)
					current=current->left;
				else 
					current=current->right;
			}
			return current;
		}
		static node* _successor(node *root) 
		{
			if(root->right)
			{
				root=root->right;
				while(root->left)
					root=root->left;
				
				return root;
			}
			
			node *y=root->parent;
			while(y&&root==y->right)
			{
				root=y;
				y=y->parent;
			}
			
			return y;
		}
		static node* _predecessor(node *root) 
		{
			if(root->left)
			{
				root=root->left;
				while(root->right)
					root=root->right;

				return root;
			}
			
			node *y=root->parent;
			while(y&&root==y->left)
			{
				root=y;
				y=y->parent;
			}
			return y;
		}
		void _fill_iterator_buffer()
		{
			_begin_buffer.current=_root;
			if(_begin_buffer.current)
				_begin_buffer.is_active=true;
			while(_begin_buffer.current->left!=NULL)
				_begin_buffer.current=_begin_buffer.current->left;
			
			_end_buffer.current=_root;
			if(_end_buffer.current)
				_end_buffer.is_active=false;
			while(_end_buffer.current->right!=NULL)
				_end_buffer.current=_end_buffer.current->right;
			
			lastchanged=false;
		}
	public:
		treap()
		{
			lastchanged=true;
			_root=NULL;
		};
	
		template<class iterator_type> treap(iterator_type begin,iterator_type end)
		{
			lastchanged=true;
			_root=NULL;
			while(begin!=end)
				insert(*(begin++));
		}
		
		void clear()
		{
			lastchanged=true;
			_recurse_delete(_root);
			_root=NULL;
		}
		
		void insert(const key_type &KEY)
		{
			lastchanged=true;
			//---------------- constructing the node-------------------
			node *newnode=new node;
			newnode->key=KEY;
			newnode->priority=_random.max();
			newnode->left=newnode->right=newnode->parent=NULL;
			
			//------------ inserting in a binary tree way -------------
			node *position=_root;
			node *parent=NULL;
			while(position!=NULL)
			{
				parent=position;
				if(newnode->key<position->key)
					position=position->left;
				else
					position=position->right;
			}
			
			if(parent)
			{
				if(newnode->key<parent->key)
					parent->left=newnode;
				else
					parent->right=newnode;
				newnode->parent=parent;
			}
			else
				_root=newnode;
		
			_increase_priority(newnode,_random());
		};
		
		bool find(key_type KEY) const
		{
			return _find(KEY)!=NULL;
		}
		
		void erase(const key_type &key)
		{
			lastchanged=true;
			node *current=_find(key);
			if(current)
			{
				_decrease_priority(current,_random.max()); // have to think for a better alternative to represent max key.
				
				if(current->parent)
				{
					if(current==current->parent->right)
						current->parent->right=NULL;
					else if(current==current->parent->left)
						current->parent->left=NULL;
				}
				else
					_root=NULL;
				delete current;
			}
		};
		
		pair<treap<T,R>,treap<T,R> > split(const key_type KEY)
		{
			lastchanged=true;
			insert(KEY);
			_increase_priority(_find(KEY),_random.min());
			
			treap *less=new treap;
			treap *greater=new treap;
			
			less->_root   =_root->left;
			greater->_root=_root->right;
			
			less->_root->parent=greater->_root->parent=NULL;
			delete _root;
			_root=NULL;
			return make_pair(*less,*greater);
		}
			
		template<class TT,class RR> friend treap<TT,RR> merge(treap<TT,RR> &a,treap<TT,RR> &b,typename treap<TT,RR>::priority_type val);
		
		~treap()
		{
			lastchanged=true;
			clear();
		};

		;
		class iterator:public std::iterator<bidirectional_iterator_tag,key_type,size_t,key_type&,key_type>
		{	
			node *current;
			bool is_active;
			public:
				
				iterator()
				{
					current=NULL;
					is_active=false;
				}
				iterator operator ++(int)
				{
					iterator temp=*this;
					node *successor=_successor(current);
					if(successor)
						current=successor;
					else
						is_active=false;
					return temp;
				}
				
				iterator operator ++()
				{
					node *successor=_successor(current);
					if(successor)
						current=successor;
					else
						is_active=false;
					return *this;
				}				
				
				iterator operator --(int)
				{
					iterator temp=*this;
					if(is_active)
						current=_predecessor(current);
					else
						is_active=true;
					
					return temp;
				}
				
				iterator operator --()
				{
					if(is_active)
						current=_predecessor(current);
					else
						is_active=true;
					return *this;
				}
				
				const key_type operator *() const
				{
					if(is_active)
						return current->key;
					else
						return key_type();
				}
				
				bool operator ==(const iterator &i2) const
				{
					return is_active==i2.is_active&&current==i2.current;
				}
				bool operator !=(const iterator &i2) const
				{
					return !(*this==i2);
				}
				friend class treap;
		};
		
		
		iterator begin()
		{
			if(lastchanged)
				_fill_iterator_buffer();
				
			return _begin_buffer;
		}
		iterator end()
		{
			if(lastchanged)
				_fill_iterator_buffer();
			return _end_buffer;
		}
		iterator erase(const iterator a)
		{
			lastchanged=true;
			if(a.is_active)
			{
				node *current=a.current;
				a++;
				if(current)
				{
					_decrease_priority(current,_random.max()); // have to think for a better alternative to represent max key.
	
					if(current->parent)
					{
						if(current==current->parent->right)
							current->parent->right=NULL;
							else if(current==current->parent->left)
							current->parent->left=NULL;
					}
					else
						_root=NULL;
					delete current;
				}	
				return a;
			}
				
		}
	#ifdef DEBUG_LEVEL
		size_t height(node *root)
		{
			if(!root)
				return 0;
			else
				return 1+max(height(root->left),height(root->right));
		}
		size_t height()
		{
			return height(_root);
		}
	#endif
		
		friend class treap::iterator;	
	private:
		bool lastchanged;
		treap::iterator _begin_buffer;
		treap::iterator _end_buffer;
	
};


template<class TT,class RR> treap<TT,RR> merge(treap<TT,RR> &A,treap<TT,RR> &B,typename treap<TT,RR>::priority_type KEY)
{
	treap<TT,RR> *newtreap=new treap<TT,RR>;
	
	newtreap->insert(KEY);
	
	newtreap->_root->right= B._root;
	newtreap->_root->left = A._root;

	newtreap->_root->right->parent=newtreap->_root;
	newtreap->_root->left->parent=newtreap->_root;
	
	A._root=NULL;
	B._root=NULL;
	
	newtreap->erase(KEY);
	
	return *newtreap;
}


//------------------------------------------------------------------------------
class random
{
	private:
	//	default_random_engine generator;
		
	public:
		typedef double value_type;
		value_type min() const
		{
			return -0.0001;
		}
		
		value_type max() const
		{
			return 1.0;
		}
		
		value_type operator()()
		{
			return rand();//generate_canonical<double,63>(generator);
		}
};


int main()
{	
	treap<int,random> a;
	
	map<int,int> heights;
	for(int i=0;i<1000;i++)
	{
		a.clear();
		for(int j=0;j<5000;j++)
			a.insert(j);
		heights[a.height()]++;
	}
	
	for(auto i=heights.begin();i!=heights.end();i++)
		cout<<i->first<<" "<<i->second<<endl;
}
