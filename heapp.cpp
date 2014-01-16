//----------------------- Headers-----------------------

#include<iostream>
#include<vector>

//----------------------------------------------------

template<class T> class minHeap
{
	private:
		std::vector<T> heap;
		
		//--------------- TO get the position-----------------------------------
		int parent(int i) {return i>>1;}
		int left(int i) {return i<<1;}
		int right(int i) {return (i<<1)+1;}
		
		//--------------- internal functions. not to be shared to the user---
		void minHeapify(std::vector<T> & HEAP, int i)
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
                	std::swap(HEAP[i],HEAP[minPos]);
                    minHeapify(HEAP,minPos);
            	}
        	}
    	}
        void buildMinHeap(std::vector<T> &HEAP)
		{
			int n=HEAP.size()-1;
     	
     		for(int i=n/2;i>=1;i--)
            	minHeapify(HEAP,i);
		}
		
		
		
	public:
		
		minHeap()
		{
			heap.clear();
			heap.push_back(0);// false as acc to my assumtion heap starts with 1 pos;
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
                  std::swap(heap[parent(i)],heap[i]);
                  i=parent(i);
     		} 
		}

};



int main()
{
	minHeap<int>  myheap;
	using namespace std;

	myheap.insert(1);
	
	myheap.insert(3);
	myheap.insert(5);
	myheap.insert(0);
	myheap.insert(6);
	myheap.insert(2);

	for(int i=0;i<10;i++)
	{
		cout<<myheap.extractMin();
	}

}
