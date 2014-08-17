#include<iostream>
#include<conio.h>
using namespace std;

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

int newDirection(int previousDirection){
	switch(previousDirection){
		case UP: return LEFT;
		case DOWN: return RIGHT;
		case RIGHT: return UP;
		case LEFT: return DOWN;
	}
}

pair<int,int> makeMove(pair<int,int> currentLocation,int direction){
	switch(direction){
		case UP: currentLocation.second++; break;
		case DOWN: currentLocation.second--;break;
		case RIGHT: currentLocation.first++;break;
		case LEFT: currentLocation.first--;break;
	}
	return currentLocation;
}
int main(){
	int points = 10000;
	cout<<points<<endl;
	
	pair<int,int> currentPoint = make_pair(0,0);
	
	int lastMoveCount = 1;
	int movesLeft = 1;
	
	int direction = RIGHT;
	
	while(points--){
		cout<<currentPoint.first<<" "<<currentPoint.second<<endl;
		currentPoint = makeMove(currentPoint,direction);
		movesLeft --;
		if(movesLeft==0)
		{
			movesLeft = lastMoveCount +1;
			lastMoveCount = movesLeft;
			direction = newDirection(direction);
		}
	}
}
