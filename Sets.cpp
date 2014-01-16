#include<map>
#include<iostream>
using namespace std;

template<class T> set
{
	map<T,bool> element;
	public:
		bool insert(const T &E)
		{
			if(element[E]) return false;
			else 
			{
				element[E]=true;
				return true;
			}
		}
		
		bool isDere(const T &E)
		{
			return element[E];
		}		
};


int main()
{


}
