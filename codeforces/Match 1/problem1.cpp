#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i=0;i<n;i++)
		cin>>array[i];
	
	sort(array.rbegin(),array.rend());
	
	list<int> solution;
	solution.push_back(array[0]);
	
	for(int i=1;i<array.size();i++)
	{
		if(solution.back()>array[i])
			solution.push_back(array[i]);
		else if(solution.front()>array[i])
			solution.push_front(array[i]);
	}
	
	cout<<solution.size()<<endl;
	for(list<int>::iterator i=solution.begin();i!=solution.end();i++)
		cout<<*i<<" ";
}
