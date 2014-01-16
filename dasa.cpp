#include<queue>
#include<iostream>
using namespace std;


int main()
{
	priority_queue<int,greater> heap;
	heap.push(5);
	heap.push(4);
	heap.push(5);
	heap.push(6);
	
	while(heap.size())
	{
		cout<<heap.top();
		heap.pop();
	}
	
}

