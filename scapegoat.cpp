/*
	Name: ScapeGoat Trees
	Copyright: 
	Author: 
	Date: 29/11/13 11:11
	Description: 
*/

#include<iostream>
#include<vector>
using namespace std;

template<class T,size_t alpha> class scapegoat_tree
{
	public:
		typedef T key_type;
	private:
		
		struct node
		{
			key_type key;
			node *left,*right,*parent;
			bool is_deleted;
		};
		
		node *_root;
		size_t _size;
		size_t _deleted;
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
		
		node *buildtree(vector<node*> &nodes, int left,int right)
		{
			
			if(left>right)
				return NULL;
			if(left==right)
			{
				nodes[left]->left=nodes[left]->right=nodes[left]->parent=NULL;
				return nodes[left];
			}
			else
			{
				size_t mid=(left+right)/2;
				nodes[mid]->left=buildtree(nodes,left,mid-1);
				nodes[mid]->right=buildtree(nodes,mid+1,right);
				if(nodes[mid]->left)
					nodes[mid]->left->parent=nodes[mid];
				if(nodes[mid]->right)
					nodes[mid]->right->parent=nodes[mid];
				
				return nodes[mid];
				
			}
		}
		node * _rebuild_tree_insert(node *root)
		{
		
			node *begin,*end;
			begin=root;
			
			while(begin->left)
				begin=begin->left;
			end=root;
			
			while(end->right)
				end=end->right;
			
			vector<node *> nodes;
			while(begin!=end)
			{
				nodes.push_back(begin);
				begin=_successor(begin);
			
			}
			nodes.push_back(end);
			cout<<"Before";
			for(int i=0;i<nodes.size();i++)
				cout<<nodes[i]->key<<" ";
			node *root2=buildtree(nodes,0,nodes.size()-1);	
			cout<<endl;
			cout<<"after";
			inorder(root2);
			
			cin.get();
			return root2;
		}
		
		void _rebuild_tree_delete()
		{
			node *root=_root;
			node *begin,*end;
			begin=root;
			
			while(begin->left)
				begin=begin->left;
			end=root;
			
			while(end->right)
				end=end->right;
			
			vector<node *> nodes;
			vector<node *> deletednodes;
			while(begin!=end)
			{
				if(!begin->is_deleted)
					nodes.push_back(begin);
				else
					deletednodes.push_back(begin);
				begin=_successor(begin);
			}
			if(!end->is_deleted)
				nodes.push_back(end);
			else
				deletednodes.push_back(end);
			
			for(size_t i=0;i<deletednodes.size();i++)
			{
				_size--;
				_deleted--;
				delete deletednodes[i];
			}
			
			_root=buildtree(nodes,0,nodes.size()-1);	
		}
		
		pair<size_t,node *> _find(const key_type &KEY) const
		{
			size_t depth=0;
			node *current=_root;
			while(current&&(current->is_deleted||current->key!=KEY))
			{
				depth++;
				if(KEY<current->key)
					current=current->left;
				else 
					current=current->right;
			}
			return make_pair(depth,current);
		}
		void _recurse_delete(node *root)
		{
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
		
		size_t size(node *root)
		{
			
			if(!root)
				return 0;
			else
				return 1+size(root->left)+size(root->right);
		}
	public:
		scapegoat_tree()
		{
			_root=NULL;
			_size=0;
			_deleted=0;
		}
		
		template<class iterator_type> scapegoat_tree(iterator_type begin,iterator_type end)
		{
			_root=NULL;
			_size=0;
			_deleted=0;
			while(begin!=end)
				insert(*(begin++));
		}
		void clear()
		{
			_recurse_delete(_root);
			_size=0;
			_deleted=0;
			_root=NULL;
		}
		
		bool find(const key_type &KEY) const
		{
			return _find(KEY).second!=NULL;
		}
		void insert(const key_type &KEY)
		{
			node *newnode=new node;
			newnode->key=KEY;
			newnode->is_deleted=false;
			newnode->left=newnode->right=newnode->parent=NULL;
			
			
			node *position=_root;
			node *parent=NULL;
			
			size_t depth=0;
			while(position!=NULL)
			{
				depth++;
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
			
			_size++;
			
			
		
			size_t formula=(1<<(depth/alpha))>>1;
			if(formula> _size)
			{
				node *scapegoat=newnode;
				size_t height=0;
				size_t sz=1;
				
				
				while(((1<<(height/alpha))>>1)<sz)
				{
					if(scapegoat->parent)
					{
						if(scapegoat==scapegoat->parent->left)
							sz+=1+size(scapegoat->parent->right);
						else
							sz+=1+size(scapegoat->parent->left);
					}	
					scapegoat=scapegoat->parent;
					height++;
				}
				
				if(!scapegoat->parent)
				{
					_root=_rebuild_tree_insert(_root);
				}
				else
				{
					if(scapegoat==scapegoat->parent->left)
						scapegoat->parent->left=_rebuild_tree_insert(scapegoat);
					else
						scapegoat->parent->right=_rebuild_tree_insert(scapegoat);
				}
			}
		
			
			
		}
		size_t size()const
		{
			return _size-_deleted;
		}
		
		void erase(const key_type &KEY)
		{
			node *deletenode=_find(KEY).second;
			if(deletenode)
			{
				deletenode->is_deleted=true;
				_deleted++;
				if(2*_deleted>=_size)
					_rebuild_tree_delete();	
			}
		}
		
		size_t height(node *root)
		{
			if(!root)
				return 0;
			else
				return 1+max(height(root->left),height(root->right));
		}
		size_t height()
		{
			height(_root);
		}
		void inorder(node *root)
		{
			if(!root)
				return;
			else
			{
				inorder(root->left);
				cout<<root->key<<" ";
				inorder(root->right);
			}
		}
		void inorder()
		{
			inorder(_root);
		}
};

int main()
{

	scapegoat_tree<int,2> a;
	for(int i=0;i<1000;i++)
	{
		a.insert(i);
		a.inorder();
		cout<<endl<<endl;
	}
	cout<<a.height();
	cout<<endl<<endl;
	for(int i=0;i<100;i++)
		cout<<a.find(i);
	

}
