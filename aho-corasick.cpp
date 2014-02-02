/*
	Name: Aho-Corasick Algorithm
	Copyright: 
	Author: Shobhit Saxena
	Date: 02/02/14 01:02
	Description: Aho Corasick solves the exact set matching problem in O(sizeof(Set)+O(size of Text)+O(no of pattern occurences)) 
*/

#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

template<class CHAR,class Hash,size_t R> class ahoCorasickAutomation
{
	public:
		typedef CHAR character_type;
		typedef Hash hash_type;
	private:
		
		struct node
		{
			node* G[R];
			size_t count;
			node* F;
			
			node()
			{
				for(int i=0;i<R;i++)
					G[i]=NULL;
				count=0;
				F=NULL;
			}
		};
		
		node *root;
		hash_type hash;
		
		void clearMachine(node *root)
		{
			if(root)
			{
				for(size_t i=0;i<R;i++)
				{
					if(root->G[i]!=root)
						clearMachine(root->G[i]);
				}
				delete root;
			}
		}
		
	public:
		ahoCorasickAutomation()
		{
			root=NULL;
		}
		
		template<class iterator> void insert( iterator begin, iterator end)
		{
			if(root==NULL)
				root=new node;
			
			node *current=root;
			while(begin!=end)
			{
				size_t hashed=hash(*begin);
				if(!current->G[hashed])
					current->G[hashed]=new node;
				current=current->G[hashed];	
				begin++;
			}
			current->count++;
		}
		void buildAutomation()
		{
			queue<node *> Q;
			for(int i=0;i<R;i++)
			{
				if(!root->G[i])
					root->G[i]=root;
				else
				{
					Q.push(root->G[i]);
					root->G[i]->F=root;
				}
			}
			while(!Q.empty())
			{
				node *current=Q.front();
				Q.pop();
				for(int i=0;i<R;i++)
				{
					node *next=current->G[i];
					node *failure=current->F;
					if(next)
					{
						Q.push(next);
						while(!failure->G[i])	failure=failure->F;	
						next->F=failure->G[i];
						next->count+=next->F->count;
					}
				}
			}
		}
		
		template<class iterator> size_t find(iterator begin,iterator end)
		{
			node *current=root;
			size_t result=0;
			while(begin!=end)
			{
				size_t hashed=hash(*begin);
				while(!current->G[hashed])current=current->F;
				current=current->G[hashed];
				result+=current->count;
				begin++;
			}
			return result;
		}
		
		void clear()
		{
			clearMachine(root);
			root=NULL;
		}
		
		~ahoCorasickAutomation()
		{
			clear();
		}
};

class hash
{
	public:
		size_t operator ()(char a)
		{
			return a-'a';
		}
};

int main()
{
	ahoCorasickAutomation<char, ::hash,26> A;
	int n;
	cin>>n;
	while(n--)
	{
		string x;
		cin>>x;
		A.insert(x.begin(),x.end());
	}	
	A.buildAutomation();
	string x;
	while(cin>>x)
		cout<<A.find(x.begin(),x.end())<<endl;
}
