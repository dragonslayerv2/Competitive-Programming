#include<iostream>
#include<vector>
using namespace std;

vector<vector<char> > board;

inline bool isPossible(int x,int y){
	if(x<0||y<0||x>=board.size()||y>=board.size())
		return false;
	else
		return true;
}
int getMinesAround(int x,int y){
	int ans=0;
	if(isPossible(x+1,y+1))
		ans+=(board[x+1][y+1]=='*');
	if(isPossible(x+1,y))
		ans+=(board[x+1][y]=='*');
	if(isPossible(x+1,y-1))
		ans+=(board[x+1][y-1]=='*');
	if(isPossible(x-1,y+1))
		ans+=(board[x-1][y+1]=='*');
	if(isPossible(x-1,y))
		ans+=(board[x-1][y]=='*');
	if(isPossible(x-1,y-1))
		ans+=(board[x-1][y-1]=='*');
	if(isPossible(x,y-1))
		ans+=(board[x][y-1]=='*');
	if(isPossible(x,y+1))
		ans+=(board[x][y+1]=='*');
	return ans;
}
int doClick(int x,int y){
	int ans=0;
	if(isPossible(x,y)&&board[x][y]=='.'){
		ans=1;
		board[x][y]='^';
		
		if(!getMinesAround(x,y)){
			ans+= doClick(x+1,y+1)+
					doClick(x+1,y)+
					doClick(x+1,y-1)+
					doClick(x-1,y+1)+
					doClick(x-1,y)+
					doClick(x-1,y-1)+
					doClick(x,y-1)+
					doClick(x,y+1);
		}
	}
	return ans;
}


int main(){
	freopen("in1.txt","r",stdin);
	freopen("out1.txt","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		cout<<"Case #"<<t+1<<": ";
		int n;
		cin>>n;
		board.assign(n,vector<char>(n));
		int openCells=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				cin>>board[i][j];
				if(board[i][j]=='.')
					openCells++;
			}
		
		int click=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(board[i][j]=='.'){
						int minesAround=getMinesAround(i,j);
						if(!minesAround){
							openCells-=doClick(i,j);
							click++;
						}
					}
				}
			}
		click+=openCells;
		cout<<click<<endl;
	}
}
