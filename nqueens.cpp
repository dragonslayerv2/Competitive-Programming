/*
	Name: N queens problem
	Copyright: 
	Author: Shobhit Saxena
	Date: 10/11/13 23:37
	Description: 
*/

#include<iostream>
#include<vector>
using namespace std;


inline void print(vector<int> &board)
{
	for(int i=0;i<board.size();i++)
		cout<<board[i]<<" ";
	cout<<endl;
}


inline bool ispossible(int h1,int v1,int h2,int v2)
{
	if(h1==h2) // same horizontal
		return false;
	else if(v1==v2) // same vertical
		return false;
	else if(v1-v2==h1-h2||v1-v2==h2-h1) // diagnols
		return false;
	else
		return true;
}


int count=0;
void solve(vector<int> &board,int current=0)
{
	if(current==board.size())
	{
		count++;
		print(board);
	}
	else
	{
		for(int vpos=0;vpos<board.size();vpos++)
		{
			bool allowed=true;
			for(int hpos=0;hpos<current;hpos++)
			{
				if(!ispossible(hpos,board[hpos],current,vpos))
				{
					allowed=false;
					break;
				}
			}
			if(allowed)
			{
				board[current]=vpos;
				solve(board,current+1);
			}
		}	
	}
}

int main()
{
	int n;
	cin>>n;
	vector<int> board(n);
	count=0;
	solve(board);
	cout<<count;
}
