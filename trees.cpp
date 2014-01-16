#include<vector>
#include<list>
#include<iostream>
using namespace std;


class tree
{
	public:
		typedef int value_type;
		class node
		{
				int _parent;
				value_type _data;
				list<size_t> _children;
				public:
					node()
					{
						parent=-1;
					}
					size_t parent() const
					{
						return _parent;
					}
					const list<size_t> &children() const
					{
						return _children;
					}
					operator value_type&()
					{
						return _data;
					}
					void make_parent(node &child)
					{
						_children.push_back(child);
					}
		};
	private:
		
		vector<node> nodes;
	
	public:
		tree()
		{}
		
		tree(size_t size)
		{
			assign(size);
		}
		
		void assign(size_t size)
		{
			clear();
			nodes.resize(size);
			for(int i=0;i<nodes.size();i++)
				nodes[i];
		}
				
		node &operator[](size_t pos)
		{
			return node[pos];
		}
		
		void clear()
		{
			nodes.clear();
		}
		~tree()
		{
			clear();
		}
};

int main()
{

}
