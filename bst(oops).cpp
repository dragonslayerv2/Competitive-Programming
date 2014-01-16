#include<iostream>
using namespace std;

class node
{
	public:
		int rollno;
		string name;
		
		node *left;
		node *right;
		
		node(int ROLL,string NAME)
		{
			rollno=ROLL;
			name=NAME;
			left=right=NULL;
		}		
};


class bst
{
	node *root;
	
	node **_insert(int rollno,node **root)
	{
		if(*root==NULL)
			return root;
		else if((*root)->rollno>rollno)
			return _insert(rollno,&((*root)->left));
		else
			return _insert(rollno,&((*root)->right));
	}
	
	node * _lookup(int rollno,node *root)
	{
		if(root==NULL)
			return NULL;
		if(root->rollno==rollno)
			return root;
		else if(root->rollno<rollno)
			return _lookup(rollno,root->right);
		else
			return _lookup(rollno,root->left);
	}
	public:
		bst()
		{
			root=NULL;
		}
		
		void insert(int rollno,string name)
		{
			node **place=_insert(rollno,&root);
			*place=new node(rollno,name);
		}
		
		string lookup(int rollno)
		{
			node *place=_lookup(rollno,root);
			if(place==NULL)
				return "";
			else
				return place->name;
		}

};
int main()
{
	bst BST;
	BST.insert(111501,"Yashvinder");
	BST.insert(111526,"Umesh");
	BST.insert(111498,"Aakash");
	BST.insert(111392,"Shobhit");
	cout<<BST.lookup(111392);
}
