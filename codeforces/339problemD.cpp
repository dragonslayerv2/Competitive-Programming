/*
	Name: Winner tree implementation
	Copyright: 
	Author: Shobhit Saxena
	Date: 03/09/13 01:33
	Description: Configure the funcptr in constructor according to needs
*/



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


template<class T> class winner_tree
{
		vector<vector<T> > tree;
		T (*outfunc)(T a,T b,int level);
	public:
		winner_tree(vector<T> &array, T (*funcptr)(T a,T b,int level))
		{
			outfunc=funcptr;
			int size=0;
			int array_size=array.size();
			while(array_size)
			{
				size++;
				array_size>>=1;
			}
			tree.clear();
			tree.resize(size);
			
			tree[0]=array;
			int current_level=1;
			int current_level_size=array.size()/2;
			
			while(current_level_size)
			{
				tree[current_level].resize(current_level_size);
				for(int i=0;i<current_level_size;i++)
				{
					tree[current_level][i]=outfunc(tree[current_level-1][2*i],tree[current_level-1][2*i+1],current_level);
				}	
				current_level_size/=2;
				current_level++;
			}
		}
		void update(int pos,T value)
		{
			tree[0][pos]=value;
		//	debug();
			int current_level=1;
			while(current_level<tree.size())
			{
				pos/=2;
				
				tree[current_level][pos]=outfunc(tree[current_level-1][2*pos],tree[current_level-1][2*pos+1],current_level);
				current_level++;
				
			}
		}
		T query()
		{
			return tree.back().back();
		}
		
		
		void debug()
		{
			for(int i=0;i<tree.size();i++)
			{
				for(int j=0;j<tree[i].size();j++)
				{
					cout<<tree[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};

long long output(long long a,long long b,int level)
{
	if(level%2)
		return a|b;
	else
		return a^b;
}

int main()
{
	int n;
	cin>>n;
	int m;
	cin>>m;
	long long size=1;
	for(int i=0;i<n;i++)
		size<<=1;
	
	vector<long long> arr(size);
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	
	winner_tree<long long> tree(arr,output);
	
	while(m--)
	{
		int pos;
		long long val;
		cin>>pos>>val;
		tree.update(pos-1,val);
		cout<<tree.query()<<endl;
	}
}
