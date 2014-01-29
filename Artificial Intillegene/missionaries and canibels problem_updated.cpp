/*
	Name: Missionaries and Canibel
	Copyright: 
	Author: Shobhit Saxena
	Date: 29/01/14 13:22
	Description: Graph search to solve missionaries and canibel problem.
				 BFS.
*/

#include<iostream>
#include<queue>
#include<map>
using namespace std;

inline void unpack(int &mLeft,int &cLeft,int &boat,int a)
{
	mLeft=a/100;
	cLeft=(a/10)%10;
	boat=a%10;
}

inline int pack(int mLeft,int cLeft,int boat)
{
	int answer=mLeft;
	answer*=10;
	answer+=cLeft;
	answer*=10;
	answer+=boat;
	return answer;
}

inline bool isValid(int a)
{
	int mLeft,cLeft,boat;
	unpack(mLeft,cLeft,boat,a);
	
	if(mLeft!=0&&cLeft>mLeft)
		return false;
	else if((3-mLeft)!=0&&(3-cLeft)>(3-mLeft))
		return false;
	else
		return true;
}


//------------------------------------------------------------------------------
int main()
{
	int initialState = 330; 
	int finalState 	 = 1; 
	/*	
		Most Significant Digit 	: Missionaries on left bank
		Second 					: Canibels on left bank
		Left most				: Boat on which bank
	*/
					
	map<int,int> parent; // state parent relationship
	parent[initialState]=initialState;
	queue<int> Q;
	Q.push(initialState);
	while(!Q.empty()&&Q.front()!=finalState)
	{
		
		int current=Q.front();	
		Q.pop();
		
		int mLeft,cLeft,boat;
		unpack(mLeft,cLeft,boat,current);

		if(boat==0)
		{
			for(int m=0;m<=mLeft;m++)
				for(int c=0;c<=cLeft;c++)
					if(m+c!=0&&m+c<=2)
					{
						int move=pack(mLeft-m,cLeft-c,1);		
						if(isValid(move)&&!parent[move])
						{
							parent[move]=current;
							Q.push(move);
						}
					}		
		}
		
		else
		{
			for(int m=0;m<=(3-mLeft);m++)
				for(int c=0;c<=(3-cLeft);c++)
					if(m+c!=0&&m+c<=2)
					{
						int move=pack(mLeft+m,cLeft+c,0);		
						if(isValid(move)&&!parent[move])
						{
							parent[move]=current;
							Q.push(move);
						}
					}	
		}
	}
	
	deque<int> moves;
	if(!parent[finalState])
		cout<<"No such moves"<<endl;
	else
	{
		while(parent[finalState]!=finalState)
		{
			moves.push_front(finalState);
			finalState=parent[finalState];
		}
		moves.push_front(initialState);
		for(int i=0;i<moves.size();i++)
			cout<<moves[i]<<endl;
	}
}
