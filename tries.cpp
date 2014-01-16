#include<iostream>
#include<map>
#include<vector>
#include<list>
using namespace std;


template<class T,int size,class hash> class trie
{
	private:
		struct node
		{
			node *child[size]; 
			
			node()
			{
				for(int i=0;i<size;i++)
					child[i]=NULL;
			}
		};
		
		node root;
		map<T,size_t> count;
	public:
		trie()
		{
		}
		void insert(
		
		
};
int main()
{
	
}
