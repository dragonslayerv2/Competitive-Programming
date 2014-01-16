/*
	Name: Symmetric Min Max Heap
	Copyright: 
	Author: 
	Date: 31/12/13 04:30
	Description: This is a heap that can be used as a double ended priority queue.
				Per opearation cost is O(log n)
				Refer to http://publications.cse.iitm.ac.in/778/1/IPL99.pdf  for more details
*/

#include<iostream>
#include<vector>
using namespace std;

template<class T> class min_max_heap
{
	public:
		typedef T key_type;
	private:
		vector<key_type> tree;
		
		size_t parent(size_t pos)
		{
			return pos>>1;
		}
		size_t Lchild(size_t pos)
		{
			return pos<<1;
		}
		size_t Rchild(size_t pos)
		{
			return (pos<<1)+1;
		}
		
		size_t Lnode(size_t pos)
		{
			return Lchild(parent(parent(pos)));
		}
		
		size_t Rnode(size_t pos)
		{
			return Rchild(parent(parent(pos)));
		}
		
		size_t Lsibling(size_t pos)
		{
			return Lchild(parent(pos));
		}
		
		size_t Rsibling(size_t pos)
		{
			return Rchild(parent(pos));
		}
		
		void push_down(size_t pos)
		{
			while(1)
			{
				size_t newpos;
				if(pos=Lchild(parent(pos)))
					newpos=minpos(pos);	
				else
					newpos=maxpos(pos);
				if(newpos==pos)
					break;
				else
				{
					swap(tree[pos],tree[newpos]);
					pos=newpos;
				}
			}
		}
		
		size_t minpos(size_t pos)
		{
			int MINpos=pos;
			if(Lchild(pos)<tree.size()&&tree[Lchild(pos)]<tree[MINpos])
				MINpos=Lchild(pos);
			if(Rchild(pos)<tree.size()&&tree[Rchild(pos)]<tree[MINpos])
				MINpos=Rchild(pos);
			
			size_t siblingpos;
			if(pos==Lchild(parent(pos)))
				siblingpos=Rchild(parent(pos));
			else
				siblingpos=Lchild(parent(pos));
			if(siblingpos<tree.size())
			{
				if(tree[siblingpos]<tree[MINpos])
					MINpos=siblingpos;
				
				if(Lchild(siblingpos)<tree.size()&&tree[Lchild(siblingpos)]<tree[MINpos])
					MINpos=Lchild(siblingpos);
				if(Rchild(siblingpos)<tree.size()&&tree[Rchild(siblingpos)]<tree[MINpos])
					MINpos=Rchild(siblingpos);
			}
			return MINpos;
		}
		
		size_t maxpos(size_t pos)
		{
			int MAXpos=pos;
			if(Lchild(pos)<tree.size()&&tree[Lchild(pos)]>tree[MAXpos])
				MAXpos=Lchild(pos);
			if(Rchild(pos)<tree.size()&&tree[Rchild(pos)]>tree[MAXpos])
				MAXpos=Rchild(pos);
			
			size_t siblingpos;
			if(pos==Lchild(parent(pos)))
				siblingpos=Rchild(parent(pos));
			else
				siblingpos=Lchild(parent(pos));
			if(siblingpos<tree.size())
			{
				if(tree[siblingpos]>tree[MAXpos])
					MAXpos=siblingpos;
				
				if(Lchild(siblingpos)<tree.size()&&tree[Lchild(siblingpos)]>tree[MAXpos])
					MAXpos=Lchild(siblingpos);
				if(Rchild(siblingpos)<tree.size()&&tree[Rchild(siblingpos)]>tree[MAXpos])
					MAXpos=Rchild(siblingpos);
			}
			return MAXpos;
		}
	public:
		min_max_heap()
		{
			tree.resize(2); // 0 is empty first node is dummy.
		}
		
		void push(const key_type &a)
		{
			size_t pos=tree.size();
			tree.push_back(a);
			if(size()>1) // more than 1 elements
			{
				if(tree[pos]<tree[Lsibling(pos)])
				{
					swap(tree[pos],tree[Lsibling(pos)]);
					pos=Lsibling(pos);
				}
				while(parent(pos)!=1) 
				{
					if(tree[pos]<tree[Lnode(pos)])
					{
						swap(tree[pos],tree[Lnode(pos)]);
						pos=Lnode(pos);
					}
					else if(tree[pos]>tree[Rnode(pos)])
					{
						swap(tree[pos],tree[Rnode(pos)]);
						pos=Rnode(pos);
					}
					else
						break;
				}
			}
		}
		
		key_type& min()
		{
			return tree[2];
		}
		key_type &max()
		{
			if(size()==1)
				return tree[2];
			return tree[3];
		} 
		
		void pop_min()
		{
		
			swap(tree[2],tree[tree.size()-1]);
			tree.resize(tree.size()-1);
			if(size()>2)
				push_down(2);			
		
		}
		void pop_max()
		{
			swap(max(),tree[tree.size()-1]);
			tree.resize(tree.size()-1);
			if(size()>2)
				push_down(3);
		}
		
		size_t size()
		{
			return tree.size()-2; // 2 extra space acclocated.
		}
		void clear()
		{
			tree.clear();
			tree.resize(2);
		}
		void debug()
		{
			for(int i=1;i<tree.size();i++)
				cout<<tree[i]<<" ";
		}
};

int main()
{
	min_max_heap<int> a;
	
	while(1)
	{
		char command;
		cin>>command;
		if(command=='i')
		{
			int value;
			cin>>value;
			a.push(value);	
		}
		else if(command=='p')
		{
			char command2;
			cin>>command2;
			if(command2=='m')
				a.pop_min();
			else
				a.pop_max();
		}
		else
			a.clear();
		cout<<a.min()<<"\t"<<a.max()<<endl;
	}
}
