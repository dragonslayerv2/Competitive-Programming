#include<iostream>
using namespace std;


int main()
{
	int t;
	cin>>t;
	
	int two=0,three=0,four=0;
	while(t--)
	{
		char S[4];
		cin>>S;
		if(S[0]=='1'&&S[2]=='2')
			two++;
		else if(S[0]=='1'&&S[2]=='4')
			four++;
		else if(S[0]=='3'&&S[2]=='4')
			three++;
	}
	
	int solution=0;
	
	solution+=min(three,four);
	three-=solution;
	four-=solution;
	
	solution+=three;
	
	solution+=two/2;
	two%=2;
	
	solution+=four/4;
	four%=4;
	
	if(two)
	{
		solution++;
		two--;
		four-=2;
	}
	
	if(four>0)
		solution++;	
	
	cout<<solution+1;	
}
