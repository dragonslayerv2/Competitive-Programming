#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
template <typename value_type> class Heap {
	private:
		vector<value_type> heap_vec;
		map<int, unsigned> pos;
		size_t size;
		inline unsigned parent(unsigned node)
		{
			return (node - 1)/2;
		}
		inline unsigned lchild(unsigned node)
		{
			return (2 * node + 1);
		}
		unsigned rchild(unsigned node)
		{
			return (2 * node + 2);
		}
		bool (*property)(value_type, value_type);
		void upheap(unsigned node)
		{
			if (node != 0 && !property(heap_vec[parent(node)], heap_vec[node])) {
				//-----
				pos[heap_vec[node].key] = parent(node);
				pos[heap_vec[parent(node)].key] = node;	
				//-----
				swap(heap_vec[parent(node)], heap_vec[node]);
				upheap(parent(node));
			} 
		}
		void downheap(unsigned node)
		{
			if (lchild(node) >= size && rchild(node) >= size) 
				return;
			else if (lchild(node) < size && rchild(node) < size){
				unsigned swap_node = (property(heap_vec[node], heap_vec[lchild(node)])) ?  node : lchild(node); 
				swap_node = (property(heap_vec[swap_node], heap_vec[rchild(node)]))? swap_node: rchild(node);
				//-------
				pos[heap_vec[swap_node].key] = node;
				pos[heap_vec[node].key] = swap_node;
				//-------
				swap(heap_vec[swap_node], heap_vec[node]);
				if (swap_node == node)
					return;
				else 
					downheap(swap_node);
			} else if (lchild(node) < size) {
				if (!property(heap_vec[node], heap_vec[lchild(node)])) {
					//--------
					pos[heap_vec[node].key] = lchild(node);
					pos[heap_vec[lchild(node)].key] = node;
					//--------
					swap(heap_vec[node], heap_vec[lchild(node)]);
				}
			}
		}
	public:
		Heap(bool (*iproperty)(value_type, value_type))
		{
			property = iproperty;
			size = 0;
		}
		bool push(value_type element)
		{
			heap_vec.push_back(element);
			pos[element.key] = size;
			upheap(size);
			size++;
			return 1;
		}
		bool pop()
		{
			
			if (empty())
				return 0;
			else {
				//-------
				pos.erase(heap_vec[0].key);
				pos[heap_vec[size - 1].key] = 0;
				//-------
				swap(heap_vec[0], heap_vec[size - 1]);
				heap_vec.pop_back();
				size--;
				downheap(0);
				return 1;
			}
		}
		int size_h() {
			return heap_vec.size();
		}
		value_type top()
		{
			return heap_vec[0];
		}
		bool empty()
		{
			if (size == 0)
				return 1;
			else
				return 0;
		}
		
		//Specialised for Dijkstra and Prims
		bool increase_key(int key, int increase)
		{
			if (!pos.count(key)) {
				return 0;
			}
			else {
				heap_vec[pos[key]].value = increase;
				downheap(pos[key]);
				return 1;
			}
		}
#ifdef DEBUG
	void print()
	{
		for (int i = 0; i < size ; i++)
			cout << "(" << heap_vec[i].key << " " << heap_vec[i].value << ") ";
		cout << endl;
	}
#endif
};

struct key_value {
	int key;
	int value;
	key_value(int ikey, int ivalue)
	{
		key = ikey;
		value = ivalue;
	}
};

bool min(key_value a, key_value b)
{
	return ((a.value < b.value)? 1: 0);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int c, q, n = 0, i, priority;
		vector<int> rem(1000010);
		Heap<key_value> H(min);
		scanf("%d%d", &c, &q);
		while (q--) {
			int ch;
			scanf("%d%d", &ch, &i);
			if (ch == 1) {
				if (n < c) {
					if (rem[i]) {
						H.increase_key(i, priority);
					} else {
						H.push(key_value(i ,priority));
						n++;
					}
				} else {
					if (rem[i])
						H.increase_key(i, priority);
					else {
						rem[H.top().key] = 0;
						H.pop();
						H.push(key_value(i, priority));
					}
				}	
				priority++;
				rem[i] = 1;
			} else {
				if (rem[i])
					cout << "YES\n";
				else 
					cout << "NO\n";
			}
		}
	}
	return 0;
}
