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
			debug();
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

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	winner_tree<int> mytree(a,[](int a,int b,int level){if(level%2)(return max(a,b);});
	mytree.update(4,7);
	mytree.debug();
}
