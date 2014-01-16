#include<iostream>
using namespace std;

class BST
{
	private:
		struct node
		{
			int data;
			node *left, *right;
		};
		node * root;
		
		void _insert(node **head,int n)
		{
			if(*head==NULL)
			{
				node *newnode=new node;
				newnode->data=n;
				newnode->left=NULL;
				newnode->right=NULL;
				*head=newnode;
			}
			else if((*head)->data>n)
				_insert(&((*head)->left),n);
			else
				_insert(&((*head)->right),n);
		}
		
		bool _exist(node *head,int n)
		{
			if(!head)
				return false;
			else if(head->data==n)
				return true;
			else if(head->data>n)
				return _exist(head->left,n);
			else
				return _exist(head->right,n);
		}
	public:
		
		BST()
		{
			root=NULL;
		}
		void insert(int n)
		{
			_insert(&root,n);
		}
		bool exist(int n)
		{
			return _exist(root,n);
		}
		
};


int main()
{
	BST b;
	b.insert(1);
	b.insert(5);
	b.insert(7);
	for(int i=0;i<10;i++)
	{
		cout<<i<<" "<<b.exist(i)<<endl;
	}
}
