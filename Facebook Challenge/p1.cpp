#include<iostream>
#include<deque>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		deque<int> digits;
		while(n)
		{
			digits.push_front(n&1);
			n/=2;
		}
		
		int i=0,j=1;
		int chance=0;
		while(i<digits.size()&&j<digits.size())
		{
			if(digits[j]==0)
			{
				chance+=j-i;
				i++;
			}
			j++;
		}		
		
		if(chance%2==0)
			cout<<"Second Player";
		else
			cout<<"First Player";
			
		cout<<endl;
	}
}

