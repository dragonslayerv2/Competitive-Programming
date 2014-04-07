#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int count[]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string n;
		cin>>n;
		long long total=0;
		for(int i=0;i<n.size();i++)
			total+=count[n[i]-'0'];
		cout<<total<<endl;
	}
}
