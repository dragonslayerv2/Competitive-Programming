#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<list>
#include<cstdio>
using namespace std;

int main(){
	freopen("test3.txt","r",stdin);
	int n,t;
	cin>>n>>t;
	vector<int> w(n);
	for(int i=0;i<n;i++)
		cin>>w[i];
	vector<int> order(t);
	
	vector<pair<int,int> > priority(n);
	for(int i=0;i<priority.size();i++)
		priority[i]=make_pair(INT_MAX,i);
	
	for(int i=0;i<t;i++){
		cin>>order[i];
		order[i]--;
		priority[order[i]].first=min(priority[order[i]].first,i);
	}
	sort(priority.begin(),priority.end());
	vector<int> book(n);
	for(int i=0;i<n;i++)
		book[i]=priority[i].second;
	int cost=0;
	for(int i=0;i<t;i++){
		
		int pos=0;
		for(int j=0;book[j]!=order[i];j++){
			cost+=w[book[j]];
			pos++;
		}
 		for(int j=pos;j>0;j--)
			book[j]=book[j-1];
		book.front()=order[i];
	}
	cout<<cost;
}
