#include<iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;

class ConnectingGameDiv2{
	
	vector<string> board;
	int counts[1000];
	vector<vector<vector<int> > > dp;
	
	int f(int x,int y,bool lastSame){
		if(dp[x][y][lastSame]!=-1)
			return dp[x][y][lastSame];
		
		int ans	= 0;
		if(!lastSame)
			ans+=counts[board[x][y]];
	
		if(y==board[0].size()-1)
			return ans;
		else
		{
			int newAdditions=INT_MAX;
			int newX=x-1;
			int newY=y+1;
			if(newX>=0&&newY>=0&&newX<board.size()&&newY<board[0].size())
				newAdditions=min(newAdditions,f(newX,newY,board[newX][newY]==board[x][y]));
				
			newX=x;
			newY=y+1;
			if(newX>=0&&newY>=0&&newX<board.size()&&newY<board[0].size())
				newAdditions=min(newAdditions,f(newX,newY,board[newX][newY]==board[x][y]));
				
			newX=x+1;
			newY=y+1;
			if(newX>=0&&newY>=0&&newX<board.size()&&newY<board[0].size())
				newAdditions=min(newAdditions,f(newX,newY,board[newX][newY]==board[x][y]));
			dp[x][y][lastSame]= ans+newAdditions;
			return dp[x][y][lastSame];
		}
	}
	
	public:
		int getmin(vector <string> board){
			dp.resize(board.size(),vector<vector<int> >(board[0].size(),vector<int>(2,-1)));
			this->board=board;
			int minimumValue=INT_MAX;
			
			for(int i=0;i<board.size();i++)
				for(int j=0;j<board[i].size();j++)
					counts[board[i][j]]++;
			
			for(int i=0;i<board.size();i++){
				minimumValue=min(minimumValue ,f(i,0,false));
			}
			return minimumValue;
		}
};
int main()
{
	cout<<ConnectingGameDiv2().getmin({	"AAAAAAaaabcdefg", 
										"AAAAAAhhDDDDDDD", 
										"AAAAiAjDDDDDDDD", 
										"AAAAiijDDDDDDDD", 
										"AAAAAAAkDDDDDDD", 
										"AAAAoAAAlDDDDDD", 
										"AAApBnAAlDDDDDD", 
										"srqBBBmmmmDDDDD"});
}
