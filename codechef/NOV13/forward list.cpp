#include<list>
#include<forward_list>
#include<iostream>
using namespace std;


int main()
{
	forward_list<int> a;
	
	a.push_front(5);
	forward_list<int>::iterator x=a.begin();
	 
	for(int i=0;i<10;i++)
		x=a.insert_after(x,i);
	
	for(forward_list<int>::iterator i=a.begin();i!=a.end();i++)
		cout<<*i<<endl;
}
