#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<climits>
using namespace std;

#define INVALID INT_MAX

void printMap(vector<vector<char> > &cityMap,int x,int y){
	for(int i=0;i<cityMap.size();i++){
		for(int j=0;j<cityMap[i].size();j++)
			if(i==x&&j==y)
				cout<<"*";
			else
				cout<<cityMap[i][j];	
		cout<<endl;
	}
	cout<<endl<<endl<<endl;
}

#define validate(x,y) ((x>=0)&&x<(2*row-1)&&(y>=0)&&(y<2*column-1))

//#define DEBUG
int main(){
	freopen("straight.in","r",stdin);
	freopen("straight.out","w",stdout);
	int row,column;
	cin>>row>>column;
	getchar();
	vector<vector<char> > cityMap(2*row-1,vector<char>(2*column-1));
	for(int i=0;i<2*row-1;i++){
		for(int j=0;j<2*column-1;j++)
			cityMap[i][j]=getchar();		
		getchar();
	}

	const int SOURCE_X = 2*row-2;
	const int SOURCE_Y = 0;
	const int DESTINATION_X = 0;
	const int DESTINATION_Y = 2*column-2;
	
	vector<vector<int> > shortestPaths(2*row-1,vector<int>(2*column-1,-1));
	for(int i=0;i<shortestPaths.size();i++)
		for(int j=0;j<shortestPaths[i].size();j++)
			if(cityMap[i][j]==' ')
				shortestPaths[i][j]=INT_MAX;
	
			
	queue<pair<int,int> > bfsQueue;
	shortestPaths[DESTINATION_X][DESTINATION_Y]=0;
	bfsQueue.push(make_pair(DESTINATION_X,DESTINATION_Y));
	while(!bfsQueue.empty()) {
		int x=bfsQueue.front().first;
		int y=bfsQueue.front().second;
		bfsQueue.pop();
		
		vector<pair<int,int> > nextPoints;
		
		
		switch(cityMap[x][y]){
			case '+':	if(validate(x-1,y)&&shortestPaths[x-1][y]==-1)
							nextPoints.push_back(make_pair(x-1,y));
						if(validate(x+1,y)&&shortestPaths[x+1][y]==-1)
							nextPoints.push_back(make_pair(x+1,y));
						if(validate(x,y-1)&&shortestPaths[x][y-1]==-1)
							nextPoints.push_back(make_pair(x,y-1));
						if(validate(x,y+1)&&shortestPaths[x][y+1]==-1)
							nextPoints.push_back(make_pair(x,y+1));
				break;
			case '-':	if(validate(x,y-1)&&shortestPaths[x][y-1]==-1)
							nextPoints.push_back(make_pair(x,y-1));
						if(validate(x,y+1)&&shortestPaths[x][y+1]==-1)
							nextPoints.push_back(make_pair(x,y+1));
				break;
			case '|':	if(validate(x-1,y)&&shortestPaths[x-1][y]==-1)
							nextPoints.push_back(make_pair(x-1,y));
						if(validate(x+1,y)&&shortestPaths[x+1][y]==-1)
							nextPoints.push_back(make_pair(x+1,y));
				break;
		}
		for(int i=0;i<nextPoints.size();i++)
		{
			shortestPaths[nextPoints[i].first][nextPoints[i].second]=shortestPaths[x][y]+1;
			bfsQueue.push(make_pair(nextPoints[i].first,nextPoints[i].second));
		}
	}
	
	const int UP=0;
	const int DOWN=1;
	const int LEFT=2;
	const int RIGHT=3;
	
	pair<int,int> at=make_pair(SOURCE_X,SOURCE_Y);
	int direction;
	if(shortestPaths[at.first-1][at.second]<shortestPaths[at.first][at.second+1])
		direction=UP;
	else
		direction=RIGHT;
	if(direction==UP){
		at.first--;
		cout<<"N";
	}
	else{
		at.second++;		
		cout<<"E";
	}
	cout<<endl;
	
	while(at!=make_pair(DESTINATION_X,DESTINATION_Y)){
		
		#ifdef DEBUG
			printMap(cityMap,at.first,at.second);
		#endif
		pair<int,int> newPoint=at;
		switch(direction){
			case UP: newPoint.first--;
				break;
			case DOWN: newPoint.first++;
				break;
			case RIGHT: newPoint.second++;
				break;
			case LEFT: newPoint.second--;
				break;
		}
		if(cityMap[at.first][at.second]=='+'){
			bool changed=false;
			int x=at.first;
			int y=at.second;
			int newDirection;
			
			int currentShortest;
			if(validate(newPoint.first,newPoint.second))
				currentShortest = shortestPaths[newPoint.first][newPoint.second];
			else
				currentShortest =INT_MAX;
			if(validate(x-1,y)&&shortestPaths[x-1][y]<currentShortest){
				currentShortest=shortestPaths[x-1][y];
				changed=true;
				newDirection=UP;
			}
			if(validate(x+1,y)&&shortestPaths[x+1][y]<currentShortest){
				currentShortest=shortestPaths[x+1][y];
				changed=true;
		 		newDirection=DOWN;
			}
			if(validate(x,y-1)&&shortestPaths[x][y-1]<currentShortest){
				currentShortest=shortestPaths[x][y-1];
				changed=true;
				newDirection=LEFT;
			}
			if(validate(x,y+1)&&shortestPaths[x][y+1]<currentShortest){
				currentShortest=shortestPaths[x][y+1];
				changed=true;
				newDirection=RIGHT;
			}
			if(changed)
			{
				switch(direction){
					case UP: if(newDirection==RIGHT)
								cout<<'R';
							 else 
							 	cout<<'L';
						break;
					case DOWN:if(newDirection==LEFT)
								cout<<'R';
							 else 
							 	cout<<'L';
						break;
					case LEFT:if(newDirection==UP)
								cout<<'R';
							 else 
							 	cout<<'L';
						break;
					case RIGHT:if(newDirection==DOWN)
								cout<<'R';
							 else 
							 	cout<<'L';
						break;
				}	
				direction=newDirection;
				newPoint=at;
				switch(direction){
					case UP: newPoint.first--;
						break;
					case DOWN: newPoint.first++;
						break;
					case RIGHT: newPoint.second++;
						break;
					case LEFT: newPoint.second--;
						break;
				}	
			}
			else
				cout<<'F';
		}
		at=newPoint;
	}
}
