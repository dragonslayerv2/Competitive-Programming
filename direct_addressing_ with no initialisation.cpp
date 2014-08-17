/*
	Name: Direct addressing with O(1) initialisation.
	Copyright: 
	Author: Shobhit Saxena
	Date: 16/11/13 17:32
	Description: Refer to Cormen Q11.4 For hints.
*/

#include<iostream>
using namespace std;


template<size_t sz>class directmap
{
	private:
		int _set[sz];
		int _stack[sz];
		int _top;
		
	public:
		directmap()
		{
			clear();
		}
		void set(size_t pos)
		{
			if(!isSet(pos))
			{
				_top++;
				_set[pos]=_top;
				_stack[_top]=pos;
			}
		}
		bool isSet(size_t pos)
		{
			if(_top<=0)
				return false;
			else
			{
				if(_set[pos]<=_top&&_stack[_set[pos]]==pos)
					return true;
				else
					return false;
			}
		}
		
		void reset(size_t pos)
		{
			if(isSet(pos))
			{
				_set[_stack[_top]]=_set[pos]; 
				swap(_stack[_top],_stack[_set[pos]]);
				_set[pos]=_top;
				_top--;
			}
		}
		
		size_t size()
		{
			return sz;
		}
		
		void clear(){
			_top=0;
		}
		
};



int main()
{
	directmap<80> a;
	a.set(10);
	a.set(11);
	a.set(12);
	for(int i=0;i<a.size();i++)
		cout<<a.isSet(i);
	
	a.reset(10);
	
	for(int i=0;i<a.size();i++)
		cout<<a.isSet(i);
	
	
}
