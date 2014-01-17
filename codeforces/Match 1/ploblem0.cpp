#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<int> cards(n);
	for(int i=0;i<n;i++)
		cin>>cards[i];
		
	int first,last;
	first=0;
	last=cards.size()-1;
	
	long long first_player=0;
	long long second_player=0;
	
	bool first_player_turn=true;
	while(first<=last)
	{
		long long current;
		if(cards[first]>cards[last])
		{
			current=cards[first];
			first++;
		}
		else
		{
			current=cards[last];
			last--;
		}
		if(first_player_turn)
			first_player+=current;
		else
			second_player+=current;
		first_player_turn^=true;
	}
	cout<<first_player<<" "<<second_player;
}
