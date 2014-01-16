/*
	Name: Btree
	Copyright: 
	Author: Shobhit Saxena
	Date: 13/11/13 13:44
	Description: Refer to Cormen for pseudocode
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class value,int t> class BTree
{
	public:
			typedef value value_type;
	private:
		struct node
		{
			int n	;
			vector<value> key;
			vector<node *> child;
			bool leaf;
		};
		node * root;
		int sz;
		
		void split_child(node *x,int i)
		{
		
			node *z=new node;
			node *y=x->child[i];
			
			
			value_type median=y->key[t-1];
			z->leaf=y->leaf;
			
			z->n=t-1;
			
			z->key.resize(t-1);
			for(int j=0;j<t-1;j++)
				z->key[j]=y->key[j+t];
			
			if(!y->leaf)
			{
				z->child.resize(t);
				for(int j=0;j<t;j++)
					z->child[j]=y->child[j+t];
			}

			y->n=t-1;
			
			y->key.resize(t-1);
			y->child.resize(t);
			
			x->child.resize(x->child.size()+1);
			
			for(int j=x->n;j>=i+1;j--)
				x->child[j+1]=x->child[j];
			
			x->child[i+1]=z;
			
			x->key.resize(x->key.size()+1);
			
			for(int j=x->n-1;j>=i;j--)
				x->key[j+1]=x->key[j];
			
			x->key[i]=median;
			x->n++;
		}	
		
		
		void BTree_insert_non_full(node *x,value_type k)
		{
			int i=x->n-1;
			if(x->leaf)
			{
				x->key.resize(x->key.size()+1);
	
				while(i>=0&&k<x->key[i])
				{
					x->key[i+1]=x->key[i];
					i--;
				}
				
				x->key[i+1]=k;
				x->n++;
			}
			else
			{
				while(i>=0&&k<x->key[i])
					i--;
				i++;
				if(x->child[i]->n==2*t-1)
				{
					split_child(x,i);
					if(k>x->key[i])
						i++;
				}
				BTree_insert_non_full(x->child[i],k);
			}
		}
		
		pair<node*,int> BTree_search(node * x,const value_type &k) const
		{
			int i=0;
			while(i<x->n&&k>x->key[i])
				i++;
			if(i<x->n&&k==x->key[i])
				return make_pair(x,i);
			else if(x->leaf)
				return make_pair((node*)(NULL),i);
			else
				return BTree_search(x->child[i],k);
		}
	public:
		#define DEBUG
		#ifdef DEBUG
		void print_node(node *x)
		{
			
			cout<<"------------";
			cout<<x->n<<endl;
			for(int i=0;i<x->n;i++)
				cout<<x->key[i]<<" ";
			cout<<endl;
			cout<<"------------";
		}
		#endif
		
		
	
		BTree()
		{
			initialise();
		}
		
		template<class iterator> BTree(iterator begin,iterator end)
		{
			initialise(begin,end);
		}
		
		void initialise()
		{
			sz=0;
			root=new node;
			root->leaf=true;
			root->n=0;
		}
		
		template<class iterator> void initialise(iterator begin,iterator end)
		{
			initialise();
			while(begin!=end)
				insert(*begin);
		}
		
		size_t size() const
		{
			return sz;
		}
		
		bool empty() const
		{
			return !size();
		}
		void push(value_type k)
		{
		
			if(root->n==2*t-1)
			{
				node * s=new node;
				s->leaf=false;
				s->n=0;
				s->child.push_back(root);
				root=s;
				split_child(s,0);
				BTree_insert_non_full(s,k);				
			}
			else
				BTree_insert_non_full(root,k);
	
			sz++;
		}
		
		bool find(const value_type &element) const
		{
			return BTree_search(root,element).first!=NULL;
		}
};

int main()
{
	BTree<int,3> B;
	for(int i=0;i<=100;i+=2)
		B.push(i);
	for(int i=0;i<=100;i++)
		cout<<B.find(i);
}
