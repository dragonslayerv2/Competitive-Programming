#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		vector<pair<int,int> > positions(26);
		
		int row=0;
		int column=0;
		for(int i=0;i<positions.size();i++){
			if(column>=n)
			{
				row++;
				column=0;
			}
			positions[i]=make_pair(row,column);
			column++;
		}
		while(q--){
			string s;
			cin>>s;
			pair<int,int> currentPosition=make_pair(0,0);
			int distance=0;
			for(int i=0;i<s.size();i++){
				pair<int,int> newPosition=positions[s[i]-'a'];
				distance+=abs(newPosition.first-currentPosition.first)+abs(newPosition.second-currentPosition.second);
				currentPosition=newPosition;
			}
			cout<<distance<<endl;
		}		
	}
}
