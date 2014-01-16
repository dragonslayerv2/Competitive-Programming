#include<iostream>
using namespace std;

template<class T> persistent_forward_list
{
	public:
		typedef T value_type;
	private:
		struct node
		{
			value_type data;
			node *next;
		};

		vector<node*> version_head;



};
int main()
{


}
