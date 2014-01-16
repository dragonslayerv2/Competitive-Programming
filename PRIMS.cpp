#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;

//-----------------------------------------------------------------------------
template<class T> class set
{
	map<T,bool> element;
	int sz;
	public:
		set()
		{
			sz=0;
			element.clear();
		}
		bool insert(const T &E)
		{
			if(element[E]) return false;
			else 
			{
				sz++;
				element[E]=true;
				return true;
			}
		}
		
		bool isMember(const T &E)
		{
			return element[E];
		}		
		int size()
		{
			return sz;
		}
};
//-----------------------------------------------------------------------------
template<class T> class minHeap
{
	private:
		vector<T> heap;
		
		//--------------- TO get the position-----------------------------------
		int parent(int i) {return i>>1;}
		int left(int i) {return i<<1;}
		int right(int i) {return (i<<1)+1;}
		
		//--------------- internal functions. not to be shared to the user---
		void minHeapify(vector<T> & HEAP, int i)
		{     
			int n=HEAP.size()-1;
        	if(i<n)
        	{
            	int minPos=i;
            
        	   	if(left(i)<=n)
      	           if(HEAP[left(i)]<HEAP[minPos])
        	           minPos=left(i); 
            	if(right(i)<=n)
                   if(HEAP[right(i)]<HEAP[minPos])
                       minPos=right(i); 
            
           		if(i!=minPos) 
            	{
                	swap(HEAP[i],HEAP[minPos]);
                    minHeapify(HEAP,minPos);
            	}
        	}
    	}
		
	public:
		
		minHeap()
		{
			heap.clear();
			heap.resize(1);// false as acc to my assumtion heap starts with 1 pos;
		}
		
		
		class HEAP_EMPTY{}; // exception handling class
		
		T min(){return heap[1];}		// return the min element
		
		T extractMin() // extract the min
		{
    		if(heap.size()<=1) throw HEAP_EMPTY();
    		T min=heap[1];
    		heap[1]=heap.back();
    		heap.pop_back();
    		
   		 	minHeapify(heap,1);
    		return min;
		}
		void insert(T element) // insert a element
		{	
     		heap.push_back(element);
     		int i=heap.size()-1;
    	 	while(heap[parent(i)]>heap[i]&&i!=1)
     		{
                  swap(heap[parent(i)],heap[i]);
                  i=parent(i);
     		} 
		}
		
		bool isEmpty()
		{
			return heap.size()<=1;
		}

};

//---------------------------------------------------------------------------
typedef int vertice;


struct edge
{
	vertice a,b;
	long long weight;
	
	public:
		bool operator >(const edge & e2)
		{
			return weight>e2.weight;
		}
		bool operator <(const edge & e2)
		{
			return weight<e2.weight;
		}
		bool operator >=(const edge & e2)
		{
			return weight>=e2.weight;
		}
		bool operator <=(const edge & e2)
		{
			return weight<=e2.weight;
		}
};





//--------------------------------------------------------------------------

int main()
{
	int v;
	cin>>v;
	
	vector<list<edge> > graph(v); // well i think in the long run it will help
	
	int e;
	cin>>e;
	
	for(int i=0;i<e;i++)
	{
		edge temp;
		cin>>temp.a;
		cin>>temp.b;
		cin>>temp.weight;
		
		graph[temp.a].push_back(temp);
		graph[temp.b].push_back(temp);		
	}
	
	set<vertice> tree;
	minHeap<edge> heap;
	
	
	//------------------------- PRIMS starts-------------------------
	long long MSTweight=0;
	tree.insert(0);
	
	for(list<edge>::iterator i=graph[0].begin();i!=graph[0].end();i++)
	{
		heap.insert(*i);
	}
	
	while(!heap.isEmpty()&&tree.size()<v) // you can put here an another check that tree is completed or not. but i dnot care.
	{
		edge e=heap.extractMin();
		
		if(!tree.isMember(e.a)) // if a yet not in the tree push it there
		{
			MSTweight+=e.weight;
			tree.insert(e.a);
			for(list<edge>::iterator i=graph[e.a].begin();i!=graph[e.a].end();i++)
				heap.insert(*i);		
		}
		else if(!tree.isMember(e.b)) // if b is not do the same with b
		{
			MSTweight+=e.weight;
			tree.insert(e.b);
			for(list<edge>::iterator i=graph[e.b].begin();i!=graph[e.b].end();i++)
				heap.insert(*i);		
		}
		// else go with the next edge
	}
	cout<<tree.size();
	cout<<"Weight of minimum spanning tree = "<<MSTweight<<endl;
}
