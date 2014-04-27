#include<iostream>
#include<map>
#include<list>
using namespace std;


template<class I, class C=list<I> > class tape
{
	public:
		typedef I input_type;
	private:
		C data;
		input_type nil;
		
	public:
		tape(input_type NIL=input_type())
		{
			erase();
			nil=NIL;
		}
		
		tape(const C &DATA,const input_type NIL=input_type())
		{
			erase();
			nil=NIL;
			store(DATA.begin(),DATA.end());	
		}
		
		template<class iterator_type> tape(const iterator_type begin,const iterator_type end,const input_type NIL=input_type())
		{
			erase();
			nil=NIL;	
			store(begin,end);
		}
		
		template<class container_type> tape operator =(const container_type & container)
		{
			erase();
			store(begin,end);
		}
		
		template<class iterator_type> void store(iterator_type begin,iterator_type end)
		{
			erase();
			back_insert_iterator<C> i=back_inserter(data);
			*i=nil;
			i++;
			while(begin!=end)			
			{
				i++;
				*i=*begin;
				begin++;
			}
		}
		
		void erase()
		{
			data.erase();
		}
		
		operator C()
		{
			C temp;
			
			for(typename C::iterator i=data.begin();i!=data.end();i++)
				temp.push_back(*i);
			temp.push_back(nil);
			return temp;
		}
		
		void size()
		{
			return data.size();
		}
		
		input_type &operator[](size_t pos)
		{
			return data[pos];
		}
		
		input_type &at(size_t pos)
		{
			return data.at(pos);
		}
		
		class iterator:public iterator_traits<C>
		{
			C &container;
			typename C::value_type nill;
			typename C::iterator dataiterator;			
		
			public:
				iterator(typename C::iterator DATA_ITERATOR, C &CONTAINER,typename C::value_type NILL):container(CONTAINER),dataiterator(DATA_ITERATOR),nill(NILL)
				{}
				iterator operator ++()
				{
					dataiterator++;
					if(dataiterator==container.end())
					{
						container.resize(container.size()+1,nill);
						dataiterator=container.end();
						dataiterator--;
					}
					return  *this;
				}
				iterator operator ++(int)
				{
					iterator temp=*this;
					dataiterator++;
					if(dataiterator==container.end())
					{
						container.resize(container.size()+1,nill);
						dataiterator=container.end();
						dataiterator--;
					}
					return temp;
				}
				
				iterator operator --()
				{
					dataiterator--;
					return  *this;
				}
				iterator operator --(int)
				{
					
					iterator temp=*this;
					dataiterator--;
					return temp;
				}
				
				typename C::value_type& operator *() 
				{
					return *dataiterator;			
				}
		}; 
		
		iterator begin()
		{
			iterator begin_iterator( data.begin(), data,nil);
			return begin_iterator;
		}
		iterator end()
		{
			iterator end_iterator( data.end(), data,nil);
			return end_iterator;
		}
};


int main()
{
	string data="GAURAV";
	tape<char,string> mytape(data,'b');
	
	
	tape<char,string>::iterator j=mytape.begin();
	for(int i=0;i<20;i++)
	{
		j++;
		cout<<*j;
	}
	

}
