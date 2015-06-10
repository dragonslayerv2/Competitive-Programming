#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;


int abs(int x){
	return x<0?-x:x;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int m,n,x,y,d;
		cin>>m>>n>>x>>y>>d;
		
		x--;
		y--;
				
		vector<vector<int> > heights(m,vector<int>(n));
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>heights[i][j];

		vector<vector<int> > distances(m,vector<int>(n,100000));
		distances[0][0]=0;
		
		queue<pair<int,int> > Q;
		Q.push(make_pair(0,0));
		
		while(!Q.empty()){
			int x=Q.front().first;
			int y=Q.front().second;
			Q.pop();
			
			for(int xDif=-1;xDif<=1;xDif++)
				for(int yDif=-1;yDif<=1;yDif++){
					if((xDif==0||yDif==0)&&xDif!=yDif){
						if(x+xDif>=0&&y+yDif>=0&&x+xDif<m&&y+yDif<n&&distances[x+xDif][y+yDif]>distances[x][y]+1&&abs(heights[x][y]-heights[x+xDif][y+yDif])<=d){
							Q.push(make_pair(x+xDif,y+yDif));
							distances[x+xDif][y+yDif]=1+distances[x][y];
						}
					}
				}
		}
		
		if(distances[x][y]>=100000)
			cout<<-1<<endl;
		else
			cout<<max(0,distances[x][y]-1)<<endl;
	}
}
