#include<iostream>
#include<vector>
using namespace std;

vector<int> getsuffixarray(string &array)
{
	
	vector<entry> L(array.size());
	vector<vector<int> > P(ceil(log(array.size()))+100,vector<int>(array.size()));
	for(int i=0;i<array.size();i++)
		P[0][i]=array[i];
//	printarray(P[0]);
	int ansrow=0;
	for(int stp=1,cnt=1;(cnt>>1)<array.size();stp++, cnt<<=1)
	{
		
		for (int i = 0; i <array.size(); i ++)
		{
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = (i + cnt < array.size() )? P[stp - 1][i + cnt] : -10000000;
			L[i].p = i;
		}
	
		sort(L.begin(), L.end() , cmp);
		
		for (int i = 0; i < array.size(); i ++)
			P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
		
		ansrow=stp;
	}
	vector<int> suffixarray(array.size());
	for(int i=0;i<array.size();i++)
	{
		suffixarray[i]=L[i].p;
	}
	return suffixarray;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		long long l;
		cin>>a>>b>>l;
		
	}
}
