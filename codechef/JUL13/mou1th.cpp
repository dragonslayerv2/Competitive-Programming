#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;

const int MOD = 1000000009;

struct entry
{
	int nr[2],p;
};

bool cmp(const entry &a, const entry &b)
{
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ) : (a.nr[0] < b.nr[0]);
}

void printarray(vector<int> &T)
{
	for(int i=0;i<T.size();i++)
	{
		cout<<T[i]<<" ";
	}
	cout<<endl;
}
	
vector<int> getsuffixarray(vector<int> &array)
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

long long getduplicates(vector<int> &suffixarray,vector<int> &arr)
{
	long long duplicates=0;
	vector<int> rank(suffixarray.size());
	
	for(int i=0;i<suffixarray.size();i++)
		rank[suffixarray[i]]=i;
		
	long long h=0;
	for(int i=0;i<suffixarray.size();i++)
	{
		if(rank[i]>0)
		{
			int j= suffixarray[rank[i]-1];
			while(i+h<suffixarray.size() && j+h<suffixarray.size() && arr[i+h]== arr[j+h])
				h++;
			duplicates+=h;
			if(h>0)
				h--;
		}
	}
	return duplicates;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<int> heightdif;
		heightdif.reserve(n-1);
		int a;
		cin>>a;
		for(int i=0;i<n-1;i++)
		{
			int b;
			cin>>b;
			heightdif.push_back(b-a);
			a=b;
		}
	//	printarray(heightdif);
		
		
		vector<int> suffixarray=getsuffixarray(heightdif);
	//	printarray(suffixarray);
		long long duplicates=getduplicates(suffixarray,heightdif);
		
		cout<<((((long long)n)*(n-1))/2-duplicates)%MOD<<endl;
	}
	return 0;
}
