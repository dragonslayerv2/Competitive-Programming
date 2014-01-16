/*
	Name: Random Access List
	Copyright:
	Author: Shobhit Saxena
	Date: 20/12/13 17:28
	Description: This is a data structure that supports the following operation.
				1. Insertion, Deletion and Access First element in O(1)
				2. Access Any Random Element in O(log n)

				Memory O(n)
*/

#include<iostream>
using namespace std;


template<class T> class random_access_list
{
	public:
		typedef T value_type;
	private:
		struct  node
		{
			value_type data;
			node *next;
			node *left,*right;
			size_t nodes;
			node()
			{
				nodes=1;
				next=left=right=NULL;
			}
		};

		node *head;
		size_t sz;

	public:
		random_access_list()
		{
			head=NULL;
			sz=0;
		}
		random_access_list(const random_access_list &l2)
		{
			assign(l2);
		}
		template<class iterator> random_access_list(iterator begin,iterator end)
		{
			assign(begin,end);
		}
		
		void assign(const random_access_list &l2) 
		{
			clear();
			if(l2.size()==0)
				return;
			for(size_t i=l2.size()-1;i>=0;i++)
				push_front(l2[i]);
		}
		template<class iterator> void assign(iterator begin,iterator end)
		{
			clear();
			if(begin!=end)
			{
				end--;
				while(end!=begin)
					push_front(*end);
				push_front(*begin);
			}
		}
	
		void push_front(const value_type& DATA)
		{
			node *newnode=new node;
			newnode->data=DATA;
			if(!head||!head->next||head->nodes!=head->next->nodes)
			{
				
				newnode->next=head;
				head=newnode;
			}
			else
			{
				
				newnode->left=head;
				newnode->right=head->next;
				newnode->next=head->next->next;
				newnode->nodes=1+newnode->left->nodes+newnode->right->nodes;
				
				head->next->next=NULL;				
				head->next=NULL;
				
				head=newnode;
			}
			sz++;
		}
		void pop_front()
		{
			node *temp=head;
			if(!head->left)
			{
				head=head->next;
			}
			else
			{
				head->left->next=head->right;
				head->right->next=head->next;
				head=head->left;
			}
			delete temp;
			sz--;
		}
		
		value_type &front()
		{
			return head->data;
		}
		value_type& operator[] (size_t pos)
		{
			node *t=head;
			while(pos>=t->nodes) // find the tree
			{	
				pos-=t->nodes;
				t=t->next;		
			}
			
			while(pos)
			{
				
				int s=t->nodes/2;
				if(pos<=s)
				{
					pos--;
					t=t->left;
				}
				
				else
				{
					pos-=s+1;
					t=t->right;
				}
			}
			return t->data;
		}
		class range_error{};
		value_type& at(size_t pos)
		{
			if(pos<0&&pos>=size())
				throw range_error();
			
			return operator[](pos); 
		}
		
		void clear()
		{
			while(sz)
				pop_front();
		}
		
		~random_access_list()
		{
			clear();
		}
		
		size_t size() const
		{
			return sz;
		}
		
		class iterator:public std::iterator<random_access_iterator_tag,value_type,size_t,value_type&,value_type*>
		{
				random_access_list *container;
				int pos;
				
			public:
				iterator()
				{
					container=NULL;
					pos=-1;
				}
				bool operator ==(const iterator b) const
				{
					return container==b.container&&pos==b.pos;
				}
				bool operator !=(iterator b) const
				{
					return !((*this)==b);
				}
				bool operator < (iterator b) const
				{
					if(container==b.container&&pos<b.pos)
						return true;
					return false;
				}
				bool operator <=(iterator b) const
				{
					return (b==*this)&&(*this<=b);
				}
				
				value_type & operator *()
				{
					return container->operator[](pos);
				}
				value_type * operator ->()
				{
					return &container->operator[](pos);
				}
				const iterator operator ++()
				{
					if(pos<container->size())
						pos++;
					return *this;
				}
				const iterator operator ++(int)
				{
					iterator temp=*this;
					if(pos<container->size())
						pos++;
					return temp;
				}

				const iterator operator --()
				{
					if(pos>0)
						pos--;
					else
						pos=container->size();
					return *this;
				}
				const iterator operator --(int)
				{
					iterator temp=*this;
					if(pos>0)
						pos--;
					else
						pos=container->size();
					return temp;
				}
				
				iterator operator +=(size_t POS)
				{
					if(pos+POS>container.size())
						pos=container.size();
					else
						pos+=POS;
					return *this;
				}
				iterator operator -=(size_t POS)
				{
					if(pos-POS>=0)
						pos-=POS;
					else
						pos=container->size();
					return *this;
				}
				iterator operator +(size_t POS)
				{
					iterator temp=*this;
					return temp+=POS;
				}
				iterator operator -(size_t POS)
				{
					iterator temp=*this;
					return temp-=POS;
				}
				
				friend class random_access_list;
		};
		
		iterator begin()
		{
			iterator a;
			a.pos=0;
			a.container=this;
			return a;
		}
		iterator end()
		{
			iterator a;
			a.pos=size();
			a.container=this;
			return a;
		}
};

int main()
{
	random_access_list<int> a;
	for(int i=0;i<100;i++)
		a.push_front(i);
	
	for(random_access_list<int>::iterator i=a.end()-1;i!=a.begin();i--)
		cout<<*i<<" ";
}
