#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	vector<int> numbers;
	for(int i=0;i<t;i++){
		int x;
		cin>>x;
		numbers.push_back(x);
	}
	vector<bool> isPossible(t+1,false);
	isPossible[t]=true;
	for(int i=t-1;i>=0;i--)
		if(i+numbers[i]+1<isPossible.size())
			isPossible[i]=isPossible[i+numbers[i]+1];
	
	bool gotAns=false;
	for(int i=1;i<isPossible.size();i++){
		if(isPossible[i]){
			cout<<i<<endl;
			gotAns=true;
		}
	}
		
	if(!gotAns)
		cout<<-1;
}
