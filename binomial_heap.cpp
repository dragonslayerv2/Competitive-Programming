/*
	Name: BINOMIAL HEAPS
	Copyright: 
	Author: SHOBHIT SAXENA
	Date: 02/11/13 17:21
	Description: REFER TO CORMEN QUESTION
*/
#include<iostream>
#include<list>
using namespace std;


template<class T> class binomial_heap
{
	public:
		typedef  T value_type;
	private:
		struct node
		{
			value_type key;
			size_t degree;
			node * child;
			node * sibling;
			node * parent;
		};
		//----------------------------------------------------------------------
		list<node *> _headlist;		
		size_t _size;
		//----------------------------------------------------------------------
		
		void addtree(node *head,node *newtree) 
		{
			newtree->parent=head;
			newtree->sibling=head->child;
			head->child=newtree;
			head->degree++;
		}
		
		void _clear(node *H)
		{
			if(!H)
				return;

			_clear(H->child);
			_clear(H->sibling);
			
			delete H;
		}
		void _copyall(node *H)
		{
			if(!H)
				return;
			
			_copyall(H->child);
			_copyall(H->sibling);
			
			push(H->key);
		}
		void copy(binomial_heap<value_type> & H2)
		{
			clear();
			for(typename list<node*>::iterator i=H2._headlist.begin();i!=H2._headlist.end();i++)
			{		
				_copyall(*i);
			}
		}
	public:
		
		//----------------------------------------------------------------------
		class empty{};
		//----------------------------------------------------------------------
		
		binomial_heap()
		{
			_size=0;
		}
		
		binomial_heap(const value_type &element)
		{
			_size=0;
			push(element);
		}
		
		template<class iterator_type> binomial_heap(iterator_type begin,iterator_type end)
		{
			push(begin,end);
		}
		
		binomial_heap( binomial_heap<value_type>& H2)
		{
			_size=0;
			copy(H2);
		}
		binomial_heap& operator=(binomial_heap<value_type>& H2)
		{
			copy(H2);
			return *this;
		}
		size_t size() const
		{
			return _size;
		}
		
		template<class iterator_type> void push(iterator_type begin,iterator_type end)
		{
			_size=0;
			while(begin!=end)
			{
				push(*begin);
				begin++;
			}
		}
		void push(const value_type &element)
		{
			if(size()==0)
			{
				node * newroot=new node;
				newroot->key=element;
				newroot->degree=0;
				newroot->child=newroot->sibling=newroot->parent=NULL;
				_headlist.push_back(newroot);
				_size=1;
			}
			else
			{
				binomial_heap<value_type> H2(element);
				//cout<<"Calling union";
				this->Union(H2);				
				H2._headlist.clear();
			}
		}	
		
		void Union(binomial_heap<value_type> &H2)
		{
			//cout<<"Reached union";
			//------------------------------------------------------------------
			binomial_heap<value_type> H0;
			binomial_heap<value_type> &H1=*this;
			
			typename list<node*>::iterator iterator1=H1._headlist.begin();
			typename list<node*>::iterator iterator2=H2._headlist.begin();
			
			while(iterator1!=H1._headlist.end()&&iterator2!=H2._headlist.end())
			{
				//cout<<"Iterator 1 degree"<<(*iterator1)->degree;
				//cout<<"Iterator 2 degree"<<(*iterator2)->degree;
				if((*iterator1)->degree<(*iterator2)->degree)
				{
				//	//cout<<"pushing iterator 1"<<endl;
					H0._headlist.push_back(*iterator1);
					iterator1++;
				}
				else if((*iterator2)->degree<(*iterator1)->degree)
				{
					////cout<<"pushing iterator 2"<<endl;
					H0._headlist.push_back(*iterator2);
					iterator2++;
				}
				else
				{
					//cout<<"Both degree equal."<<"Pusing 1"<<endl;
					
					H0._headlist.push_back(*iterator1);
					iterator1++;
				}
			}
			
			while(iterator1!=H1._headlist.end())
			{
				H0._headlist.push_back(*iterator1);
				iterator1++;
			}
			while(iterator2!=H2._headlist.end())
			{
				H0._headlist.push_back(*iterator2);
				iterator2++;
			}
			//------------------------------------------------------------------
			//cout<<"Headlist Merged";
		
			////cout<<endl;
			typename list<node*>::iterator iterator3;
			iterator1=iterator2=iterator3=H0._headlist.begin();
			
			if(H0._headlist.size()>=2)
			{
				//cout<<"Going to merge"<<endl;
				
				if(H0._headlist.size()==2)
				{
					//cout<<"Size 2 found"<<endl;
					iterator2++;
					iterator3=H0._headlist.end();
				}
				
				else if(H0._headlist.size()>2)
				{
					//cout<<"Size greater than 2"<<endl;
					iterator2++;
					iterator3=iterator2;
					iterator3++;
				}
				
				while(iterator1!=H0._headlist.end())
				{
					if(iterator2==H0._headlist.end())
					{
						//cout<<"Incrementing 1 as 2 reached to end"<<endl;
						iterator1++;
					
					}
					else if((*iterator1)->degree<(*iterator2)->degree)
					{	
						//cout<<"Iterator1 degree less than 2"<<endl;
						iterator1++;
						iterator2++;
						if(iterator3!=H0._headlist.end())
							iterator3++;
					}	
					else if(iterator3!=H0._headlist.end()&&((*iterator1)->degree==(*iterator2)->degree&&(*iterator1)->degree==(*iterator3)->degree))
					{
						//cout<<"Degree of all three same...";
						//cout<<"Incrementing all of them"<<endl;
						iterator3++;
						iterator2++;
						iterator1++;
					}
					else if((*iterator1)->degree==(*iterator2)->degree)
					{
						//cout<<"Only two degree same..";
						//cout<<"Uniting"<<endl;
						if((*iterator1)->key>(*iterator2)->key)
							swap((*iterator1),(*iterator2));
						addtree(*iterator1,*iterator2);
						iterator2=H0._headlist.erase(iterator2);
						if(iterator3!=H0._headlist.end())
							iterator3++;
					}
				}	
			}
			H1._size+=H2._size;
			H1._headlist.swap(H0._headlist);
			H0._headlist.clear();
			H2._headlist.clear();
			H2._size=0;
		}
		
		value_type min()
		{
			if(size()==0)
				throw empty();
			else
			{
				typename list<node *>::iterator i=_headlist.begin();
				value_type minimum=(*i)->key;
				i++;
				for(;i!=_headlist.end();i++)
				{
					minimum=::min((*i)->key,minimum);
				}
				return minimum;
			}
		}
		
		void extract_min()
		{
			if(!size())
				throw empty();
			typename list<node*>::iterator min_iterator=_headlist.begin();
			for(typename list<node*>::iterator current_iterator=_headlist.begin();current_iterator!=_headlist.end();current_iterator++)
			{
				if((*min_iterator)->key>(*current_iterator)->key)
					min_iterator=current_iterator;
			}
			
			
			binomial_heap<value_type> H0;
			for(node *i=(*min_iterator)->child;i!=NULL;i=i->sibling)
			{
				H0._headlist.push_front(i);
			}
			_headlist.erase(min_iterator);
			for(typename list<node*>::iterator i=H0._headlist.begin();i!=H0._headlist.end();i++)
				(*i)->sibling=NULL;
			Union(H0);
			H0._headlist.clear();
			_size--;
		}		
		
		void clear()
		{
			for(typename list<node*>::iterator i=_headlist.begin();i!=_headlist.end();i++)
			{
				_clear(*i);
			}
			_headlist.clear();
			_size=0;
		}
		bool empty()
		{
			return !size();
		}
		~binomial_heap()
		{
			clear();
		}
		
};




int main()
{
	binomial_heap<int> heap;
	binomial_heap<int> heap2;
	for(int i=30;i<40;i++)
	{
		heap.push(i);	
	}
	binomial_heap<int> heap3=heap;
	//heap3=heap;
	
	while(!heap3.empty())
	{

		heap3.extract_min();
		heap.extract_min();
		
	}
	cout<<heap.empty();
}
