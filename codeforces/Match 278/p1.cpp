#include<iostream>
#include<vector>
using namespace std;

int main(){
	string s;
	cin>>s;
	int leftCount=0;
	int rightCount=0;
	bool isPossible=true;
	vector<int> solutions;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
			leftCount++;
		else if(s[i]==')')
			rightCount++;
		else
		{
			rightCount++;
			solutions.push_back(1);
		}
	}
	if(solutions.size())
		solutions.back()+=leftCount-rightCount;
	if(solutions.size()&&solutions.back()<=0)
		isPossible=false;
	else
	{
		int hashNumber=0;
		int leftCount=0;
		int rightCount=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(')
				leftCount++;
			else if(s[i]==')')
				rightCount++;
			else
			{
				rightCount+=solutions[hashNumber++];
			}
			if(rightCount>leftCount)
			{
				isPossible=false;
				break;
			}
		}
		if(leftCount!=rightCount)
			isPossible=false;
	}
	
	if(isPossible){
		for(int i=0;i<solutions.size();i++)
			cout<<solutions[i]<<endl;
	}
	else
		cout<<-1;
}
