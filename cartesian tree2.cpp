/*
	Name: Cartesian Tree
	Copyright: 
	Author: Shobhit Saxena
	Date: 22/12/13 19:40
	Description: O(n) algorithm. Refer to MIT advanced data structures scribe notes.
*/


#include<iostream>
using namespace std;

template<class T> class cartesian_tree
{
	public:
		typedef T value_type;
	private:
		struct node
		{
			value_type data;
			node *parent,*right,*left;
			
			node(const value_type DATA=value_type())
			{
				data=DATA;
				parent=right=left=NULL;
			}
			void fix()
			{
				if(left) left->parent=this;
				if(right) right->parent=this;
			}
		};
		
		node *root;
		node *right_spine;
	public:
		cartesian_tree()
		{
			root=NULL;
			right_spine=NULL;
		}
		
		void push(const value_type &n)
		{
			node *newnode=new node(n);
		
			if(root==NULL)
				root=newnode;
			else
			{
				while(right_spine&&right_spine->data>n)
					right_spine=right_spine->parent;
				
				if(!right_spine)
				{
					newnode->left=root;
					newnode->fix();
					root=newnode;
				}	
				else
				{
					newnode->left=right_spine->right;
					right_spine->right=newnode;
					newnode->fix();
					right_spine->fix();
				}
			}
			right_spine=newnode;
		}
};


int main()
{
	cartesian_tree<int> a;
	
}
