#include<iostream>
using namespace std;


template<class VAL, class HASH,size_t R> class trie
{
	public:
		typedef VAL value_type;
		typedef HASH hash_type;
	private:
		struct node
		{
				bool is_value;
				value_type value;
				node *parent;
				node* next[R];
			public:
				node()
				{
					for(size_t i=0;i<R;i++)
						next[i]=NULL;
					is_value=false;
					parent=NULL;
					value=value_type();
				}
		};
		
		node *root;
		hash_type hash;
		void _clear_trie(node *root)
		{
			if(root)
			{
				for(size_t i=0;i<R;i++)
					_clear_trie(root->next[i]);
				delete root;
			}
		}
		void _copy_node(node *a,const node *b)
		{
			a->is_value=b->is_value;
			a->value=b->value;
			for(size_t i=0;i<R;i++)
			{
				if(b->next[i])
				{
					
					a->next[i]=new node;
					_copy_node(a->next[i],b->next[i]);
					a->next[i]->parent=a;
				}
			}
		}
	public:
		trie()
		{
			root=NULL;
		}
		
		trie(const trie &b)
		{
			root=NULL;
			clear();
			if(b.root)
			{
				root=new node;
				_copy_node(root,b.root);
			}
		}
		template<class iterator> void insert(iterator BEGIN,iterator END,value_type VALUE)
		{
			if(root==NULL)
			{
				root=new node;		
			}
			node *current=root;
			while(BEGIN!=END)
			{
				size_t hashed=hash(*BEGIN);
				if(!current->next[hashed])
				{
					current->next[hashed]=new node;
					current->next[hashed]->parent=current;
				}
				
				current=current->next[hashed];
				BEGIN++;
			}
			current->is_value=true;
			current->value=VALUE;
		}
		
		const value_type operator[](const char *a) const
		{
			size_t i;
			for(i=0;a[i]!='\0';i++);
			return find(a,a+i)->second;
		}
		
		void erase(const char *a) 
		{
			size_t i;
			for(i=0;a[i]!='\0';i++);
			return erase(a,a+i);
		}
		value_type& operator[](const char *a)
		{
			if(root==NULL)
				root=new node;		
				
			node *current=root;
			while(*a)
			{
				size_t hashed=hash(*a);
				if(!current->next[hashed])
				{
					current->next[hashed]=new node;
					current->next[hashed]->parent=current;
				}
				
				current=current->next[hashed];
				a++;
			}
			current->is_value=true;
			return current->value;
		}
		
		template<class iterator> pair<bool,value_type> find(iterator BEGIN,iterator END) const
		{
			node *current=root;
			while(current&&(BEGIN!=END))
			{
				size_t hashed=hash(*BEGIN);
				current=current->next[hashed];
				BEGIN++;
			}
			if(current&&current->is_value)
				return make_pair(true,current->value);
			else
				return make_pair(false,value_type());
		}
		
		template<class iterator> void erase(iterator BEGIN,iterator END)
		{
			node *current=root;
			while(current&&(BEGIN!=END))
			{
				size_t hashed=hash(*BEGIN);
				current=current->next[hashed];
				BEGIN++;
			}
			if(current&&current->is_value)
			{
				current->is_value=false;
				current->value=value_type();
				while(current)
				{
					size_t i;
					for(i=0;i<R;i++)
						if(current->next[i])
							break;
					
					if(i==R)
					{
						node *temp=current;
						current=current->parent;
						for(size_t i=0;i<R;i++)
							if(current->next[i]==temp)
							{
								current->next[i]=NULL;
								break;
							}
						delete temp;
					}
					else
						break;
				}
			}
		}
		
		void clear()
		{
			_clear_trie(root);
			root=NULL;
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
	trie<int,::hash,26> a;
	a["shobhit"]=1;
	a["swapnil"]=2;
	trie<int,::hash,26> b=a;
	cout<<b["shobhit"];
	b.erase("shobhit");
	cout<<a["shobhit"];
	cout<<a["shobhit"];
	cout<<b["swapnil"];
}
