/*
	Name: Division through DFA
	Copyright: 
	Author: Shobhit Saxena
	Date: 11/08/13 21:55
	Description: http://www.geeksforgeeks.org/dfa-based-division/
*/

#include<iostream>
using namespace std;

void generateTransitionFunction(int F[][2],int k)
{
	for(int states=0;states<k;states++)
	{
		int trans0=states<<1;
		int trans1=(states<<1)+1;
		if(trans0>=k)
			trans0-=k;
		if(trans1>=k)
			trans1-=k;
		
		F[states][0]=trans0;
		F[states][1]=trans1;
	}
}
int main()
{
	int k;
	cin>>k;
	int F[k][2];
	
	generateTransitionFunction(F,k);
	
	int currentState=0;
	while(1)
	{
		char a;
		cin>>a;
		cout<<(currentState=F[currentState][a-'0']);
	}

}
