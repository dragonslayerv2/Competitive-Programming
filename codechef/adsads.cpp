#include<vector>
#include<iostream>

#include<list>
using namespace std;


int main()
{
	vector<list<vector<int> > >  a;
	a.assign(5,list<vector<int> >());
	a[2].push_back(vector<int>(5));
	a[2].push_back(vector<int>(5));
	a[2].push_back(vector<int>(5));
	auto i=a[2].begin();
	i++;
	(*i)[2]=3;
	cout<<(*i).operator[](2);

	
	
}
