#include<iostream>
#include<deque>
using namespace std;


void convertBinary(int n,deque<int> &digits)
{
	while(n)
	{
		digits.push_front(n&1);
		n/=2;		
	}
}

int getTurn(const deque<int> &digits)
{
	int i=0;
	int j=1;
	int turns=0;
	while(i<digits.size()&&j<digits.size())
	{
		if(digits[j]==0)
		{
			turns+=j-i;
			i++;
		}
		j++;
	}	
	return turns%2;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		deque<int> digits;
		convertBinary(n,digits);
		if(getTurn(digits)%2==0)
			cout<<"Second Player";
		else
			cout<<"First Player";
		cout<<endl;
	}
}
