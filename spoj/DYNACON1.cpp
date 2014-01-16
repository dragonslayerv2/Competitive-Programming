#include<iostream>
#include<map>
#include<vector>
using namespace std;

template<class K> class link_cut_tree
{
	public:
		typedef K key_type;

	private:
		
		struct node
		{
			node *left,*right,*parent;
			key_type key;
			node *path_parent;
			public:
				node(key_type KEY=key_type(),node *PARENT=NULL,node *LEFT=NULL,node *RIGHT=NULL)
				{
					key=KEY;
					left=LEFT;
					right=RIGHT;
					parent=PARENT;
					path_parent=NULL;
				}	
		};		
		
		map<key_type,node *> mapper;
		
		//---------------------- SPLAY TREE FUNCTIONS--------------------------------------
		//------------------- ROTATION FUNCTION --------------------------------
		void _rotate_left(node *x)
		{
			node *y=x->right;
			x->right=y->left;
			
			if(y->left)
				y->left->parent=x;
			
			y->parent=x->parent;
			if(y->parent)
			{	
				 if(x==x->parent->left)
					x->parent->left=y;
			 	 else
					x->parent->right=y;
			}
			y->left=x;	
			x->parent=y;
		}
		
		void _rotate_right	(node *x) // assumes that y exist..:P
		{
			node *y=x->left;
			x->left=y->right;
			if(y->right)
				y->right->parent=x;
			y->parent=x->parent;
			if(y->parent)
			{	
				if(x==x->parent->left)
					x->parent->left=y;
				else
					x->parent->right=y;
			}
			y->right=x;	
			x->parent=y;
		}
		//----------------------- splay tree function-----------------------------
		void _splay(node *current)
		{
		
			while(1)
			{
				node *parent=current->parent;
				if(!parent) break;
				
				node *grandparent=parent->parent;
			
				if(!grandparent)
				{
					current->path_parent=parent->path_parent; // addition for link cut trees path parent maintainence
					parent->path_parent=NULL;
				}
				else
				{
					current->path_parent=grandparent->path_parent;
					grandparent->path_parent=NULL;
				}			
				
				
				if(!grandparent) 
				{
					
					
					if(current==parent->left)	_rotate_right(parent);
					else if(current==parent->right)	_rotate_left(parent);
				}
				
			
				else if(parent==grandparent->left && current==parent->left)
				{
					_rotate_right(grandparent);
					_rotate_right(parent);	
				}
				else if( parent==grandparent->right && current==parent->right)
				{	
					_rotate_left(grandparent);
					_rotate_left(parent);	
				}
				
				else if(parent==grandparent->left && current==parent->right) 
				{
					_rotate_left(parent);
					_rotate_right(grandparent);
				}
				else if(parent==grandparent->right && current==parent->left) 
				{
					_rotate_right(parent);
					_rotate_left(grandparent);
				}
			}
		
		}
		//------------------------ SPLAY TREE FUNCTIONS--------------------------------------
		
		void _access(node *v)
		{
		
			_splay(v);
			
			if(v->right)
			{
				v->right->path_parent=v;
				v->right->parent=NULL;
				v->right=NULL;
			}
			
			node *x=v;
			while(x->path_parent)
			{
				node *w = x->path_parent;
				_splay(w);	
				if(w->right)
				{
					w->right->path_parent=w;
					w->right->parent=NULL;
				}
				
				w->right=x;
				x->parent=w;
				
				x->path_parent=NULL;
				x=w;
			}
			_splay(v);
		}

		void _link(node *a,node*b)
		{
			_access(a);
			_access(b);
			
			a->left=b;
			b->parent=a;
		}
		
		void _cut(node *current)
		{
			_access(current);
			if(current->left)
			{
				current->left->parent=NULL;
				current->left=NULL;
			}
		}

		node* _find_root(node *current)
		{
			_access(current);
			while(current->left)
				current=current->left;
			_access(current);
			return current;
		}
		
		
	public:
		
		link_cut_tree()
		{}
		
		void cut(const key_type &KEY)
		{
			_cut(mapper[KEY]);
		}
		void insert(const key_type &KEY)
		{
			if(mapper.find(KEY)==mapper.end())
			{
				mapper[KEY]=new node(KEY);
			}
		}
		
		void link(const key_type &KEY1,const key_type &KEY2)
		{
			_link(mapper[KEY1],mapper[KEY2]);
		}
		key_type find_root(const key_type &KEY1)
		{
			return _find_root(mapper[KEY1])->key;
		}
		bool connected(const key_type &KEY1,const key_type &KEY2) 
		{
			return find_root(KEY1)==find_root(KEY2);
		}
		
		void clear()
		{
			for(typename map<key_type,node*>::iterator i=mapper.begin();i!=mapper.end();i++)
			{
				delete i->second;
			}
			mapper.clear();
		}
		~link_cut_tree()
		{
			clear();
		}
};

int main()
{
	int n,t;
	cin>>n>>t;
	link_cut_tree<int> tree;
	for(int i=1;i<=n;i++)	
		tree.insert(i);
		
	while(t--)
	{
		char command[10];
		int node1,node2;
		cin>>command>>node1>>node2;
		switch(command[0])
		{
			case 'c':   cout<<(tree.connected(node1,node2)?"YES":"NO")<<endl;
						break;
						
			case 'a':	if(tree.find_root(node1)==node1)
							tree.link(node1,node2);
						else
							tree.link(node2,node1);
						break;
			case 'r':
						break;
		}
	}
	
}
