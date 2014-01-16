/*
	Name: Binomial Heaps
	Copyright: 
	Author: Shobhit Saxenano
	Date: 02/11/13 13:17
	Description: Allow merge operation in O(log n) but decreases the time bound to find minimum to O(lg n)
				
*/

#include<iostream>
using namespace std;


template<class T> class binomial_tree
{
	public:
		typedef T value_type;
	private:
		struct node
		{
			value_type key;
			size_t degree;
			node * child;
			node * sibling;
			node * parent;
		};
		
		node *head;

	public:
		class EMPTY{};
		binomial_tree()
		{
			head=NULL;
		}
		binomial_tree(const value_type &element)
		{
			head=new node;
			head->key=element;
			head->degree=0;
			head->child=head->sibling=head->parent=NULL;
		}
		size_t degree()
		{
			if(head)
				return head->degree;
			else
				return EMPTY();
		}
		void addtree(binomial_tree &newtree) 
		{
			newtree.head->parent=head;
			newtree.head->sibling=head->child;
			head->child=newtree.head;
			head->degree++;
		}
		void print(node *H)
		{
			while(H)
			{
				cout<<H->key;
				cout<<endl;
				cin.get();
				print(H->child);
				H=H->sibling;
				
			}
		}
		void PRINT()
		{
			print(head);
		}
};

int main()
{
	binomial_tree<int> a(1);
	binomial_tree<int> b(2);
	binomial_tree<int> c(3);
	binomial_tree<int> d(4);
	
	a.addtree(b);
	c.addtree(d);
	a.addtree(c);
	a.PRINT();
}
