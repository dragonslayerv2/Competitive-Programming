#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;

int main(){
	int n,t;
	cin>>n>>t;
	map<char,int> frequency;
	for(int i=0;i<n;i++)
	{
		char card;
		cin>>card;
		frequency[card]++;
	}
	priority_queue<int> cardsFrequency;
	for(map<char,int>::iterator i=frequency.begin();i!=frequency.end();i++)
		cardsFrequency.push(i->second);
	
	long long profit=0;
	while(t){
		int topFrequency = cardsFrequency.top();
		cardsFrequency.pop();
		long long taken = min(topFrequency,t);
		t-=taken;
		profit+=taken*taken;
	}
	cout<<profit;
}
