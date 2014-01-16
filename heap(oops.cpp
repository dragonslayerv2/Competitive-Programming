#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class heap
{
	private:
		vector<int> array;
	
		int parent(int i)	{ return 	i>>1;		}
		int lchild(int i)	{ return  	i<<1;		}
		int rchild(int i)	{ return  	(i<<1)+1;	}
		
		void buildmaxheap()
		{	
			for(int i=array.size()/2;i>=1;i--)
				max_heapify(i);
		}	
		
		void max_heapify(int i)
		{
			if(i>=array.size())
				return;
			int maxpos=i;
			if(lchild(i)<array.size()&&array[maxpos]<array[lchild(i)])
				maxpos=lchild(i);
			if(rchild(i)<array.size()&&array[maxpos]<array[rchild(i)])
				maxpos=rchild(i);
			
			if(maxpos!=i)
			{
				swap(array[i],array[maxpos]);
				max_heapify(maxpos);
			}
		}
		
		
	public:
		
		heap()			{		array.push_back(INT_MAX);	}
		
		int top()		{		return array[1];			}
		
		size_t size()	{		return array.size()-1;		}
		
		bool empty()	{		return array.size()==1;		}
		
		void push(int n)
		{
			array.push_back(n);
			int i=array.size()-1;
			while(i>1&&array[parent(i)]<array[i])
			{
				swap(array[i],array[parent(i)]);
				i=parent(i);
			}
		}
		
		int pop()
		{
			array[1]=array[array.size()-1];
			array.resize(array.size()-1);
			max_heapify(1);
		}
};


int main()
{
	heap a;
	for(int i=100;i>=90;i--)
		a.push(i);
	for(int i=0;i<10;i++)
	{
		cout<<a.top()<<endl;
		a.pop();
	}
}
