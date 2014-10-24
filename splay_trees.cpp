/*
	Name: Bottom Up Splay Trees 
	Copyright: 
	Author: Shobhit Saxena
	Date: 16/12/13 19:27
	Description: Refer to the Berkeley Lecture 
				 CS 61B Lecture 34_ Splay Trees
*/

#include<iostream>


#define DEBUG
#ifdef DEBUG
	#include<queue>
#endif

using namespace std;
template<class T> class splay_tree
{
	public:
		typedef T key_type;
	private:
		
		struct node
		{
			key_type key;
			
			node *left,*right,*parent;
			node(const key_type &KEY)
			{
				left=right=parent=NULL;
				key=KEY;
			}
			
			node()
			{
				left=right=parent=NULL;
				key=key_type();
			}
		};
		
		node *_root;
		//------------------- ROTATION FUNCTION --------------------------------
		void _rotate_left(node *x)
		{
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
		//----------------------- rotation function-----------------------------
		void _splay(node *current)
		{
			#ifdef DEBUG
				cout<<"SPLAYING "<<current->key<<endl;
			#endif
			while(1)
			{
				node *parent=current->parent;
				if(!parent) return ;
				
				node *grandparent=parent->parent;
			
				if(!grandparent) // zig case
				{
					#ifdef DEBUG
						cout<<"ZIG CASE"<<endl;
					#endif
					if(current==parent->left)
						_rotate_right(parent);
					else if(current==parent->right)
						_rotate_left(parent);
				}
				
				else if(parent==grandparent->left && current==parent->left) //ZIG ZIG CASE
				{
					#ifdef DEBUG
						cout<<"ZIG ZIG CASE"<<endl;
					#endif
					_rotate_right(grandparent);
					_rotate_right(parent);
					
				}
				else if( parent==grandparent->right && current==parent->right) //ZIG ZIG CASE
				{	
					#ifdef DEBUG
						cout<<"ZIG ZIG CASE"<<endl;
						#endif
					_rotate_left(grandparent);
					_rotate_left(parent);	
					}
				
				else if(parent==grandparent->left && current==parent->right) //ZIG ZAG CASE
				{
						#ifdef DEBUG
						cout<<"ZIG ZAG CASE"<<endl;
					#endif
						_rotate_left(parent);
					_rotate_right(grandparent);
				}
				else if(parent==grandparent->right && current==parent->left) //ZIG ZAG CASE
				{
					#ifdef DEBUG
							cout<<"ZIG ZAG CASE"<<endl;
					#endif
					_rotate_right(parent);
					_rotate_left(grandparent);
				}
			}
		}
		
		void _recurse_delete(node *root)
		{
			if(root==NULL)
				return;
			else
			{
				_recurse_delete(root->left);
				_recurse_delete(root->right);
				delete root;
			}
		}
	public:
		splay_tree()
		{
			_root=NULL;
		}
		void insert(const key_type &KEY)
		{
			#ifdef DEBUG
				cout<<"INSERTING "<<KEY<<endl;
			#endif
			if(_root==NULL)
				_root=new node(KEY);
			else
			{
				node *current=_root;
				
				while(current->key!=KEY)
				{
					if(current->key<KEY)
					{
						if(current->right)	current=current->right;
						else break;
					}
					else
					{
						if(current->left) current=current->left;
						else  break;
					}
				}
				if(current->key!=KEY)
				{
					if(current->key<KEY)
					{
						current->right=new node(KEY);
						current->right->parent=current;
						current=current->right;
					}
					else
					{
						current->left=new node(KEY);
						current->left->parent=current;
						current=current->left;
					}	
				}
				_splay(current);
			}
		}
		
		bool find(const key_type &KEY)
		{
			#ifdef DEBUG
				cout<<"Finding "<<KEY<<endl;
			#endif
			node* current=_root;
			node *parent=_root;
			while(current&&current->key!=KEY)
			{
				parent=current;
				if(current->key<KEY)
					current=current->right;
				else
					current=current->left;
			}
			if(current)
			{
				_splay(current);
				return true;
			}
			else
			{
				_splay(parent);
				return false;
			}
		}
		
		void clear()
		{
			#ifdef DEBUG
				cout<<"CLEARING"<<endl;
			#endif
			_recurse_delete(_root);
			_root=NULL;
		}
		
		void erase(const key_type &KEY); // have to think about it.
		
		~splay_tree()
		{
			clear();
		}
};

int main()
{
	splay_tree<int> a;
	while(1)
	{
		int command;
		int value;
		cin>>command>>value;
		switch(command)
		{
			case 1: a.insert(value);
					break;
			case 2: a.find(value);
					break;
			case 3: a.clear();
					break;
		}
	
	}
}
