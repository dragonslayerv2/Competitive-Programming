#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
//#include<windows.h>
#define LEFT 0
#define UP 1
int main(){
	srand(time(NULL));
//	freopen("test.txt","r",stdin);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<char> > color(n,vector<char>(m,'W'));
	for(int i=0;i<k;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		color[x][y]='B';
	}
	
	int whites=n*m-k;
	vector<pair<int,pair<int,int> > > Q;
	while(whites){
		int maxX;
		int maxY;
		int removedCells=0;
		int direction;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(color[x][y]=='W')
				{
					int maxUp=1;
					int maxLeft=1;
					for(int i=x-1;i>=0&&color[i][y]=='W';i--)
						maxUp++;
						
					for(int i=x+1;i<n&&color[i][y]=='W';i++)
						maxUp++;
						
					for(int j=y-1;j>=0&&color[x][j]=='W';j--)
						maxLeft++;
					for(int j=y+1;j<m&&color[x][j]=='W';j++)
						maxLeft++;
					
					int currentRemoved=max(maxUp,maxLeft);
					int currentDirection=((currentRemoved==maxUp)?UP:LEFT);
					if(currentRemoved>removedCells||(currentRemoved==removedCells&&(rand()%2)))
					{
						direction=currentDirection;
						removedCells=currentRemoved;
						maxX=x;
						maxY=y;
					}
				}
			}
		}
		whites-=removedCells;
		
		if(direction==UP){
			for(int i=maxX-1;i>=0&&color[i][maxY]=='W';i--)
				color[i][maxY]='B';
			for(int i=maxX+1;i<n&&color[i][maxY]=='W';i++)
				color[i][maxY]='B';
		}
		else{
			for(int j=maxY-1;j>=0&&color[maxX][j]=='W';j--)
				color[maxX][j]='B';
			for(int j=maxY+1;j<n&&color[maxX][j]=='W';j++)
				color[maxX][j]='B';
		}

		color[maxX][maxY]='B';
		Q.push_back(make_pair(maxX+1,make_pair(maxY+1,direction)));
	}
	cout<<Q.size()<<endl;
	for(int i=0;i<Q.size();i++)
		cout<<Q[i].first<<" "<<Q[i].second.first<<" "<<Q[i].second.second<<endl;
}
