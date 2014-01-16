#include<iostream>
#include<algorithm>
using namespace std
;

template<class T> class dynamic_array
{
	public:
		typedef T value_type;
		typedef T* ptr_type;
		typedef T& ref_type;
	private:
		ptr_type _array;
		size_t _size;
		size_t _capacity;
	public:
		dynamic_array()
		{
			_array=NULL;
			_size=_capacity=0;
		}

		dynamic_array(size_t SIZE,const value_type &VALUE=value_type())
		{
			_array=NULL;
			_size=0;
			_capacity=0;
			resize(SIZE,VALUE);
		}
		
		dynamic_array(const dynamic_array & OB2)
		{
			*this=dynamic_array(OB2.begin(),OB2.end());
		}
		template<class iterator> dynamic_array(iterator begin,iterator end)
		{
			_array=NULL;
			_size=_capacity=0;
			while(begin!=end)
			{
				push_back(*begin);
				begin++;
			}
		}
		
		void assign(size_t SIZE,const value_type &VALUE=value_type())
		{
			clear();
			*this=dynamic_array(SIZE,VALUE);
		}
		void assign(const dynamic_array & OB2)
		{
			clear();
			*this=dynamic_array(OB2);
		}
		template<class iterator> void assign(iterator begin,iterator end)
		{
			clear();
			*this=dynamic_array(begin,end);
		}
		
		void resize(size_t SIZE,const value_type &value=value_type())
		{
			if(size()>SIZE)
			{
				if(SIZE<_capacity/3)
				{
					_capacity/=3;
					ptr_type newptr=new value_type[_capacity];
					for(int i=0;i<SIZE;i++)
						newptr[i]=_array[i];
					delete _array;
					newptr=_array;
					_size=SIZE;
				}
				else 
				{
					_size--;
				}
			}
			else if(size()<SIZE)
			{
				
				if(_capacity==0)
				{
					_capacity=SIZE;
					_size=SIZE;
					_array=new value_type[_capacity];
					for(int i=0;i<size();i++)
						_array[i]=value; 
				}
				else
				{
					if(SIZE<_capacity)
					{
						for(int i=size();i<SIZE;i++)
							_array[i]=value;
						_size=SIZE;
					}
					else
					{
					
					
						_capacity=_capacity*2;
					
						ptr_type newarray=new value_type[_capacity];
						
						for(int i=0;i<size();i++)
							newarray[i]=_array[i];
						
						for(int i=size();i<SIZE;i++)
							newarray[i]=value;
						delete _array;
						_array=newarray;
						_size=SIZE;
					
					}
				}
			}
		}
		
		void push_back(const value_type &value)
		{
			resize(size()+1);
			back()=value;
		}
		void pop_back(const value_type &value)
		{
			resize(size()-1);
		}
			
		ref_type front() const
		{
			return _array[0];
		}
		ref_type back() const
		{
			return _array[size()-1];
		}
		
		ref_type operator [](size_t pos) const
		{
			return _array[pos];
		}
		
		class out_of_range{}; //exception class
		ref_type at(size_t pos)
		{
			if(pos<size())
				return _array[pos];
			else throw out_of_range();			
		}
		
		size_t size() const
		{
			return _size;
		}
		
		
		void clear()
		{
			delete _array;
			_array=NULL;
			_size=_capacity=0;
		}
		~dynamic_array()
		{
			clear();
		}
		
		
	
		
		class iterator:public ::iterator<random_access_iterator_tag,value_type,size_t,value_type*,value_type&>
		{
			private:
				ptr_type ptr;
			public:
				iterator operator +=(size_t distance)
				{
					ptr+=distance;
					return *this;
				}
				iterator operator -=(size_t distance)
				{
					ptr-=distance;
					return *this;
				}
				iterator operator +(size_t distance)
				{
					iterator temp=*this;
					temp+=distance;
					return temp;
					
				}
				iterator operator -(size_t distance)
				{
					iterator temp=*this;
					temp-=distance;
					return temp;
				}
				iterator operator ++(int)
				{
					iterator temp=*this;
					++(*this);
					return temp;
				}
				iterator operator --(int)
				{
					iterator temp=*this;
					--(*this);
					return temp;
				}
				iterator operator ++()
				{
					ptr++;
					return *this;
				}
				iterator operator --()
				{
					ptr--;
					return *this;
				}
				ref_type operator *() const
				{
					return *ptr;
				}
				
				size_t operator -(iterator b)const
				{
					return ptr-b.ptr;
				}
				
				bool operator <(iterator b)const
				{
					return ptr<b.ptr;
				}
				bool operator ==(iterator b)const
				{
					return ptr==b.ptr;
				}
				
				bool operator <=(iterator b)const
				{
					return *this<b||*this==b;
				}
				bool operator >(iterator b)const
				{
					return !(*this<=b);
				}
				bool operator >=(iterator b)const
				{
					return !(*this<b);
				}
				
				bool operator !=(iterator b)const
				{
					return !(*this==b);
				}
				friend class dynamic_array;
		};
			iterator begin()const
			{
				iterator i;
				i.ptr=_array;
				return i;
			}
		iterator end()const
		{
			iterator i;
			i.ptr=_array+size();
			return i;
		}
};

bool check(int a)
{
	return a%2;
}
int main()
{
	dynamic_array<int> manu;
	for(int i=100;i>=1;i--)
	{
		manu.push_back(i);
	}
	stable_partition(manu.begin(),manu.end(),check);
	for(dynamic_array<int>::iterator i=manu.begin();i!=manu.end();i++)
	{
		cout<<*i<<endl;
	}
}
