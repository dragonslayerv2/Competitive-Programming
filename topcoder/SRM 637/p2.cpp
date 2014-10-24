#include<iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;

class PathGameDiv2{
	public:
		int calc(vector <string> board){
			int total=board.size()*board[0].size();			
			int hashes=0;
			for(int i=0;i<board.size();i++)
				for(int j=0;j<board[i].size();j++)
					hashes+=(board[i][j]=='#');
			
			
			vector<vector<int> > minimumDistance(board.size(),vector<int>(board[0].size(),INT_MAX));
			minimumDistance[0][0]=minimumDistance[1][0]=1;
			queue<pair<int,int> > Q;
			if(board[0][0]=='.')
				Q.push(make_pair(0,0));
			if(board[1][0]=='.')
			Q.push(make_pair(1,0));
			while(!Q.empty()){
				pair<int,int> currentPoint=Q.front();
				Q.pop();
				int x,y;
				
				x=currentPoint.first;
				y=currentPoint.second+1;
				if(x>=0&&y>=0&&x<board.size()&&y<board[0].size()&&board[x][y]=='.'&&minimumDistance[x][y]>minimumDistance[currentPoint.first][currentPoint.second]+1){
						minimumDistance[x][y]=minimumDistance[currentPoint.first][currentPoint.second]+1;
						Q.push(make_pair(x,y));
				}
				x=currentPoint.first+1;
				y=currentPoint.second;
				if(x>=0&&y>=0&&x<board.size()&&y<board[0].size()&&board[x][y]=='.'&&minimumDistance[x][y]>minimumDistance[currentPoint.first][currentPoint.second]+1){
						minimumDistance[x][y]=minimumDistance[currentPoint.first][currentPoint.second]+1;
						Q.push(make_pair(x,y));
				}
				x=currentPoint.first-1;
				y=currentPoint.second;
				if(x>=0&&y>=0&&x<board.size()&&y<board[0].size()&&board[x][y]=='.'&&minimumDistance[x][y]>minimumDistance[currentPoint.first][currentPoint.second]+1){
						minimumDistance[x][y]=minimumDistance[currentPoint.first][currentPoint.second]+1;
						Q.push(make_pair(x,y));
				}
			}
			int minimumPath=min(minimumDistance[0].back(),minimumDistance[1].back()); 
			return total-minimumPath-hashes;			
		}
};
int main(){
	cout<<PathGameDiv2().calc({"#....","...#."});
}
