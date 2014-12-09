#include<iostream>
#include<vector>
using namespace std;

#define validate(x,y,n,m) ((x)>=0&&(y)>=0&&(x)<n&&(y)<m&&!isVisited[x][y])
int totalCellsVisisted(int n,int m){
	vector<vector<bool> > isVisited(n,vector<bool>(m));
	int currentX,currentY;
	currentX=currentY=0;
	int incrementX=0,incrementY=1;
	isVisited[0][0]=true;
	int steps=1;
	while(1){
		bool done=false;
		for(int i=0;i<4;i++){
			if(validate(currentX+incrementX,currentY+incrementY,n,m)){
				currentX+=incrementX;
				currentY+=incrementY;
				isVisited[currentX][currentY]=true;
				steps++;
				done=true;
			}
			
			if(incrementX==0&&incrementY==1){
				incrementX=1;
				incrementY=0;
			}
			else if(incrementX==1&&incrementY==0){
				incrementX=0;
				incrementY=-1;
			}
			else if(incrementX==0&&incrementY==-1){
				incrementX=-1;
				incrementY=0;
			}
			else {
			
				incrementX=0;
				incrementY=1;
			}
			if(done) break;
		}
		if(!done) break;
	}
	return steps;
}

int main(){
	cout<<totalCellsVisisted(9,9);
}
