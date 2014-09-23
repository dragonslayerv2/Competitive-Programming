#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;


int main(){
	srand(time(NULL));
	int q=2000;
	const int X = 1000;
	const int Y = 1000;
	cout<<q<<endl;
	vector<vector<int> > board(X,vector<int>(Y));
	char queries[3]={'I','Q','D'};
	while(q--){
		int x=rand()%X;
		int y=rand()%Y;
		char query;
		if(board[x][y])
			query=queries[rand()%3];
		else
			query=queries[rand()%2];
		
		cout<<query<<" "<<x<<" "<<y<<endl;
		if(query=='I')
			board[x][y]++;
		else
			board[x][y]--;
	}
}
