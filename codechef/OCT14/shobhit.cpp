#include<iostream>
#include<cstdlib>
#include<time.h>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

#define LEFT 0
#define UP 1

int n,m;
void removeCells(vector<vector<char> > &color, int maxX,int maxY,int direction){
	if(direction==LEFT){
		for(int j=maxY-1;j>=0&&color[maxX][j]=='W';j--)
			color[maxX][j]='B';
		for(int j=maxY+1;j<n&&color[maxX][j]=='W';j++)
			color[maxX][j]='B';
		color[maxX][maxY]='B';
	}
	else{
		for(int i=maxX-1;i>=0&&color[i][maxY]=='W';i--)
		color[i][maxY]='B';
		for(int i=maxX+1;i<n&&color[i][maxY]=='W';i++)
			color[i][maxY]='B';
		color[maxX][maxY]='B';	
	}
}

int getMaxCells(vector<vector<char> > &color, int x,int y,int direction){
	if(direction==UP){
		int maxUp=1;
		for(int i=x-1;i>=0&&color[i][y]=='W';i--)
			maxUp++;
							
		for(int i=x+1;i<n&&color[i][y]=='W';i++)
			maxUp++;
		return maxUp;	
	}
	else{
		int maxLeft=1;
		for(int j=y-1;j>=0&&color[x][j]=='W';j--)
			maxLeft++;
		for(int j=y+1;j<m&&color[x][j]=='W';j++)
			maxLeft++;
		return maxLeft;	
	}
	
}


#define make_query(x,y,d) make_pair(make_pair(x,y),d)

typedef pair<pair<int,int>,int> query;

void printQuery(vector<query> &Q){
	cout<<Q.size()<<endl;
	for(int i=0;i<Q.size();i++)
		cout<<Q[i].first.first+1<<" "<<Q[i].first.second+1 <<" "<<Q[i].second<<endl;
}

#include<cstdio>
int main(){
//	freopen("test.txt","r",stdin);
	srand(time(NULL));
	int k;
	cin>>n>>m>>k;
	vector<vector<char> > color;
	color.assign(n,vector<char>(m,'W'));
	for(int i=0;i<k;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		color[x][y]='B';
	}	
	
	
	vector<vector<query> > Q(13);
	vector<vector<char> > tempColor;
	int queryNumber=0;
	//iterate top left to right with left move only
	tempColor=color;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(tempColor[i][j]=='W'){
				int dir=LEFT;
				Q[queryNumber].push_back(make_query(i,j,dir));
				removeCells(tempColor,i,j,dir);
			}
	
	//iterate right to left left move only
	tempColor=color;
	queryNumber++;
	for(int i=0;i<n;i++)
		for(int j=m-1;j>=0;j--)
			if(tempColor[i][j]=='W'){
				int dir=LEFT;
				Q[queryNumber].push_back(make_query(i,j,dir));
				removeCells(tempColor,i,j,dir);
			}
	
	//iterate top to bottom up move only
	tempColor=color;
	queryNumber++;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(tempColor[i][j]=='W'){
				int dir=UP;
				Q[queryNumber].push_back(make_query(i,j,dir));
				removeCells(tempColor,i,j,dir);
			}
	
	//iterate bottom right to left
	tempColor=color;
	queryNumber++;
	for(int i=n-1;i>=0;i--)
		for(int j=0;j<m;j++)
			if(tempColor[i][j]=='W'){
				int dir=UP;
				Q[queryNumber].push_back(make_query(i,j,dir));
				removeCells(tempColor,i,j,dir);
			}
	//take any random point
	tempColor=color;
	queryNumber++;
	vector<pair<int,int> > whites;
	while(1){
		whites.clear();
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(tempColor[i][j]=='W')
					whites.push_back(make_pair(i,j));
		
		if(!whites.size())
			break;
		else{
			int pos=rand()%whites.size();
			int dir;
			if(getMaxCells(tempColor,whites[pos].first,whites[pos].second,UP)>getMaxCells(tempColor,whites[pos].first,whites[pos].second,LEFT))
			 	dir=UP;
			else
				dir=LEFT;
			Q[queryNumber].push_back(make_query(whites[pos].first,whites[pos].second,dir));
			removeCells(tempColor,whites[pos].first,whites[pos].second,dir);
		}
	}
	//go with greedy
	tempColor=color;
	queryNumber++;
	int whitesCount=n*m-k;
	while(whitesCount){
		int maxX;
		int maxY;
		int removedCells=0;
		int direction;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(tempColor[x][y]=='W')
				{
					int maxUp=getMaxCells(tempColor,x,y,UP);
					int maxLeft=getMaxCells(tempColor,x,y,LEFT);
					int currentRemoved=max(maxUp,maxLeft);
					int currentDirection;
					if(maxUp==maxLeft)
						currentDirection=rand()%2;
					else
						currentDirection=((currentRemoved==maxUp)?UP:LEFT);
					
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
		whitesCount-=removedCells;
		removeCells(tempColor,maxX,maxY,direction);
		Q[queryNumber].push_back(make_query(maxX,maxY,direction));
	}
	//iterate top left to right with left move only
	tempColor=color;
	queryNumber++;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(tempColor[i][j]=='W'){
				int dir=rand()%2;
				Q[queryNumber].push_back(make_query(i,j,dir));
				removeCells(tempColor,i,j,dir);
			}
	
	//iterate right to left left move only
	tempColor=color;
	queryNumber++;
	for(int i=0;i<n;i++)
		for(int j=m-1;j>=0;j--)
			if(tempColor[i][j]=='W'){
				int dir=rand()%2;
				Q[queryNumber].push_back(make_query(i,j,dir));
				removeCells(tempColor,i,j,dir);
			}
	
	//iterate top to bottom up move only
	tempColor=color;
	queryNumber++;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(tempColor[i][j]=='W'){
				int dir=rand()%2;
				Q[queryNumber].push_back(make_query(i,j,dir));
				removeCells(tempColor,i,j,dir);
			}
	
	//iterate bottom right to left
	tempColor=color;
	queryNumber++;
	for(int i=n-1;i>=0;i--)
		for(int j=0;j<m;j++)
			if(tempColor[i][j]=='W'){
				int dir=rand()%2;
				Q[queryNumber].push_back(make_query(i,j,dir));
				removeCells(tempColor,i,j,dir);
			}
	
	// random + greedy
	tempColor=color;
	queryNumber++;
	whitesCount=n*m-k;
	while(whitesCount){
		int maxX;
		int maxY;
		int removedCells=0;
		int direction;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(tempColor[x][y]=='W')
				{
					int maxUp=getMaxCells(tempColor,x,y,UP);
					int maxLeft=getMaxCells(tempColor,x,y,LEFT);
					int currentRemoved=max(maxUp,maxLeft);
					
					
					int currentDirection;
					if(maxUp==maxLeft)
						currentDirection=rand()%2;
					else
						currentDirection=((currentRemoved==maxUp)?UP:LEFT);
					
					
					if(rand()%3==0||(currentRemoved>removedCells||(currentRemoved==removedCells&&(rand()%2))))
					{
						direction=currentDirection;
						removedCells=currentRemoved;
						maxX=x;
						maxY=y;
					}
				}
			}
		}
		whitesCount-=removedCells;
		removeCells(tempColor,maxX,maxY,direction);
		Q[queryNumber].push_back(make_query(maxX,maxY,direction));
	}
	// greedy with center distance
	tempColor=color;
	queryNumber++;
	whitesCount=n*m-k;
	while(whitesCount){
		int maxX;
		int maxY;
		int removedCells=0;
		int direction;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(tempColor[x][y]=='W')
				{
					int maxUp=getMaxCells(tempColor,x,y,UP);
					int maxLeft=getMaxCells(tempColor,x,y,LEFT);
					int currentRemoved=max(maxUp,maxLeft);
					
					
					int currentDirection;
					if(maxUp==maxLeft)
						currentDirection=rand()%2;
					else
						currentDirection=((currentRemoved==maxUp)?UP:LEFT);
					
					int lastWeightFactor   =abs(maxX-n/2)+abs(maxY-m/2)+1;
					int currentWeightFactor=abs(x-n/2)+abs(y-m/2)+1;
					if(currentRemoved*currentWeightFactor>removedCells*lastWeightFactor||(currentRemoved*currentWeightFactor==removedCells*lastWeightFactor&&(rand()%2)))
					{
						direction=currentDirection;
						removedCells=currentRemoved;
						maxX=x;
						maxY=y;
					}
				}
			}
		}
		whitesCount-=removedCells;
		removeCells(tempColor,maxX,maxY,direction);
		Q[queryNumber].push_back(make_query(maxX,maxY,direction));
	}
	// random + centre greedy
	// greedy with center distance
	tempColor=color;
	queryNumber++;
//	cout<<"At queryNo"<<queryNumber<<endl;
	whitesCount=n*m-k;
	while(whitesCount){
		int maxX;
		int maxY;
		int removedCells=0;
		int direction;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(tempColor[x][y]=='W')
				{
					int maxUp=getMaxCells(tempColor,x,y,UP);
					int maxLeft=getMaxCells(tempColor,x,y,LEFT);
					int currentRemoved=max(maxUp,maxLeft);
					
					
					int currentDirection;
					if(maxUp==maxLeft)
						currentDirection=rand()%2;
					else
						currentDirection=((currentRemoved==maxUp)?UP:LEFT);
					
					int lastWeightFactor   =(abs(maxX-n/2)*abs(maxX-n/2))+(abs(maxY-m/2)*abs(maxY-m/2))+1;
					int currentWeightFactor=abs(x-n/2)*abs(x-n/2)+abs(y-m/2)*abs(y-m/2)+1;
					if(rand()%3==0||(currentRemoved*currentWeightFactor>removedCells*lastWeightFactor||(currentRemoved*currentWeightFactor==removedCells*lastWeightFactor&&(rand()%2))))
					{
						direction=currentDirection;
						removedCells=currentRemoved;
						maxX=x;
						maxY=y;
					}
				}
			}
		}
		whitesCount-=removedCells;
		removeCells(tempColor,maxX,maxY,direction);
		Q[queryNumber].push_back(make_query(maxX,maxY,direction));
	}
	
	
	
	size_t MINQ=INT_MAX;
	for(int i=0;i<Q.size();i++)
		MINQ=min(MINQ,Q[i].size());
	
	for(int i=0;i<Q.size();i++){
		if(Q[i].size()==MINQ){
			printQuery(Q[i]);
			break;
		}
	}
}
