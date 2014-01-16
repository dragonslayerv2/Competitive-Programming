#include<iostream>
using namespace std;

class a
{
	public:
	int x;
	public:
		void operator =(a ob)
		{
			cout<<"Operator ="<<endl;
			cout<<ob.x<<endl;
			x=ob.x;
			cout<<ob.x;
		}
		a operator --(int)
		{
			cout<<"Operator decrement"<<endl;
			a ob2;
			ob2.x=x;
			
			x--;
			cout<<x<<endl;
			return ob2;
			
		}
};

int main()
{
	a ob;
	ob.x=5;
	ob=ob--;
	cout<<ob.x<<endl;
}
