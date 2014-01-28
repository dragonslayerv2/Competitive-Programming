#include<iostream>
#include<queue>
#include<map>
using namespace std;

inline void unpack(int &mLeft,int &mRight,int &cLeft,int &cRight,int a)
{
	mLeft=a/10000;
	mRight=(a/100)%10;
	cLeft=(a/1000)%10;
	cRight=(a/10)%10;
}

inline int pack(int mLeft,int mRight,int cLeft,int cRight,int boat)
{
	int answer=mLeft;
	answer*=10;
	answer+=cLeft;
	answer*=10;
	answer+=mRight;
	answer*=10;
	answer+=cRight;
	answer*=10;
	answer+=boat;
	return answer;
}

inline bool isValid(int a)
{
	int mLeft,mRight,cLeft,cRight;
	unpack(mLeft,mRight,cLeft,cRight,a);
	
	if(mLeft+mRight!=3&&cLeft+cRight!=3)
		return false;
	if(mLeft!=0&&cLeft>mLeft)
		return false;
	else if(mRight!=0&&cRight>mRight)
		return false;
	else
		return true;
}


//------------------------------------------------------------------------------
int main()
{
	int initialState = 33000; 
	int finalState = 331; 
	/*	
		First Digit : Missionaries on left bank
		Second 		: Canibels on left bank
		Third		: Missionaries on right bank
		Fourth		: Canibels on right bank
		Left most	: Boat on which bank
	*/
					
	map<int,int> parent; // state parent relationship
	parent[initialState]=initialState;
	queue<int> Q;
	Q.push(initialState);
	while(!Q.empty()&&Q.front()!=finalState)
	{
		int current=Q.front();	
		Q.pop();
		
		int mLeft,mRight,cLeft,cRight;
		unpack(mLeft,mRight,cLeft,cRight,current);
		int boat=current%10;

		if(boat==0)
		{
			for(int m=0;m<=mLeft;m++)
				for(int c=0;c<=cLeft;c++)
					if(m+c!=0&&m+c<=2)
					{
						int move=pack(mLeft-m,mRight+m,cLeft-c,cRight+c,1);		
						if(isValid(move)&&!parent[move])
						{
							parent[move]=current;
							Q.push(move);
						}
					}		
		}
		
		else
		{
			for(int m=0;m<=mRight;m++)
				for(int c=0;c<=cRight;c++)
					if(m+c!=0&&m+c<=2)
					{
						int move=pack(mLeft+m,mRight-m,cLeft+c,cRight-c,0);		
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
