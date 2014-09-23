#include<iostream>	
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<list>
using namespace std;

vector<int> nextPosition;

vector<int> a;

class segmentTree
{
	public:
		typedef int value_type;
	
	private:
		vector<vector<value_type> > tree;

		//----------------------------------------------------------------------
		int leftChild(int node)
		{
			return (node<<1)+1;
		}
		int rightChild(int node)
		{
			return (node<<1)+2;
		}
		//----------------------------------------------------------------------
		bool inRange(int nodeLeft,int nodeRight,int queryLeft,int queryRight)
		{
			if(nodeLeft>nodeRight||nodeRight<queryLeft||nodeLeft>queryRight)
				return false;
			else
				return true;
		}
		//----------------------------------------------------------------------
		
		void buildTree(const vector<value_type> &A,int low,int high,int node)
		{
			if(low==high)
			{
				tree[node].resize(1);
				tree[node][0]=A[low];
			}
			else if(low>high)
				return;
			else
			{
				buildTree(A,low,(low+high)/2,leftChild(node));
				buildTree(A,(low+high)/2+1,high,rightChild(node));
				tree[node].resize(tree[leftChild(node)].size()+tree[rightChild(node)].size());
				merge(tree[leftChild(node)].begin(),tree[leftChild(node)].end(),tree[rightChild(node)].begin(),tree[rightChild(node)].end(),tree[node].begin());
			}
		}
		
		int query(int qLeft,int qRight,value_type value, int nLeft, int nRight, int node)
		{
			if(!inRange(nLeft,nRight,qLeft,qRight))
				return INT_MAX;
			else if(nLeft>=qLeft&&nRight<=qRight){
				vector<int>::iterator i =lower_bound(tree[node].begin(),tree[node].end(),value);
				if(i==tree[node].end())
					return INT_MAX;
				else 
					return *i;
			}
				
			else
				return min(query(qLeft,qRight,value,nLeft,(nLeft+nRight)/2,leftChild(node)),query(qLeft,qRight,value,(nLeft+nRight)/2+1,nRight,rightChild(node)));
		}
	public:
		segmentTree()
		{
		}
		segmentTree(const vector<value_type> &A)
		{
			assign(A);
		}
		
		void assign(const vector<value_type> &A)
		{
			tree.clear();
			tree.resize(4*A.size());
			buildTree(A,0,A.size()-1,0);
		}
		
		int query(int left,int right,value_type value)
		{
			return query(left,right,value,0,(tree.size()/4)-1,0);
		}	
} minTree;

#include<windows.h>
vector<int> printArray;
void solve(int current){
//	cout<<"At current "<<current<<endl;
	if(current>=a.size())
		return;
	else
	{
		int currentWindow = a.size();
		pair<int,int> toPrint(-1,-1);
		map<int,int> occurences;
		for(int i=current;i<currentWindow;i++){
			int count = (++occurences[a[i]]);
			
			if(count==4)
			{
				toPrint.first=toPrint.second=a[i];
				currentWindow=i;
				break;
				occurences.clear();
			}
			int next=nextPosition[i];
//			cout<<"Checking for "<<i<<endl;
//			cout<<"Got next as "<<next<<endl;
			
			if(nextPosition[i]==i+1)
				continue;
			if(nextPosition[i]==INT_MAX)
				continue;
			int minimum = minTree.query(i+1,nextPosition[i]-1,nextPosition[i]+1);
//			cout<<"Got minimum as "<<minimum<<endl;
//			Sleep(1000);
			if(minimum<currentWindow){
				toPrint.first=a[i];
				toPrint.second=a[minimum];
				currentWindow=minimum;
			}
		}
		
		if(toPrint.first!=-1)
		{
			printArray.push_back(toPrint.first);
			printArray.push_back(toPrint.second);
			printArray.push_back(toPrint.first);
			printArray.push_back(toPrint.second);
			solve(currentWindow+1);
		}
		else 
			return;
	}
}
#include<cstdio>
int main(){
//	freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	nextPosition.resize(n);
	map<int,int> lastPosition;
	for(int i=n-1;i>=0;i--)
	{
		map<int,int>::iterator lastPos=lastPosition.find(a[i]);
		if(lastPos==lastPosition.end())
			nextPosition[i]=INT_MAX;
		else
			nextPosition[i]=lastPos->second;
		lastPosition[a[i]]=i;
	}
	minTree.assign(nextPosition);
	solve(0);
	
	cout<<printArray.size()<<endl;
	for(int i=0;i<printArray.size();i++)
		cout<<printArray[i]<<" ";
}
