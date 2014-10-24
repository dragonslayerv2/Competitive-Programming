	#include<iostream>
	#include<cstdio>
	#include<climits>
	#include<vector>
	#include<queue>
	using namespace std;
	
	
	struct cmp
	{
		bool operator()(const pair<int,pair<int,int> > &a,const pair<int,pair<int,int> > &b)
		{
			return a>b;
		}
	};
	
	
	#define make_node(x,y) make_pair(distances[x][y],make_pair(x,y))
	
	int main(){
		//freopen("test.txt","r",stdin);
		ios::sync_with_stdio(false);
		int t;
		cin>>t;
		while(t--){
			int n,m;
			cin>>n>>m;
			int matrix[n+1][m+1];
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					cin>>matrix[i][j];
			
			int destX,destY,cost;
			cin>>destX>>destY>>cost;
			
			const int INVALID=INT_MAX;
			//------------- dijkstras------------------------------
			int distances[n+1][m+1];
			bool isUsed[n+1][m+1];
		
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++){
					distances[i][j]=INVALID;
					isUsed[i][j]=false;
				}
					
			
			distances[1][1]=matrix[1][1];
			priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, cmp > Q;
			
			Q.push(make_node(1,1));
			
			while(!Q.empty())
			{
				pair<int,pair<int,int> > current=Q.top();
				Q.pop();
				if(!isUsed[current.second.first][current.second.second]){
					isUsed[current.second.first][current.second.second]=true;
					int x,y;
					x=current.second.first;
					y=current.second.second-1;
					if(x>=1&&x<=n&&y>=1&&y<=m){
						if(distances[x][y]>distances[current.second.first][current.second.second]+matrix[x][y]){
							distances[x][y]=distances[current.second.first][current.second.second]+matrix[x][y];
							Q.push(make_node(x,y));
						}
					}
					
					x=current.second.first;
					y=current.second.second+1;
					if(x>=1&&x<=n&&y>=1&&y<=m){
						if(distances[x][y]>distances[current.second.first][current.second.second]+matrix[x][y]){
							distances[x][y]=distances[current.second.first][current.second.second]+matrix[x][y];
							Q.push(make_node(x,y));
						}
					}
					
					x=current.second.first-1;
					y=current.second.second;
					if(x>=1&&x<=n&&y>=1&&y<=m){
						if(distances[x][y]>distances[current.second.first][current.second.second]+matrix[x][y]){
							distances[x][y]=distances[current.second.first][current.second.second]+matrix[x][y];
							Q.push(make_node(x,y));
						}
					}
					x=current.second.first+1;
					y=current.second.second;
					if(x>=1&&x<=n&&y>=1&&y<=m){
						if(distances[x][y]>distances[current.second.first][current.second.second]+matrix[x][y]){
							distances[x][y]=distances[current.second.first][current.second.second]+matrix[x][y];
							Q.push(make_node(x,y));
						}
					}
				}
			}
			//---------------------------------------
			if(distances[destX][destY]<=cost){
				cout<<"YES"<<endl;
				cout<<cost-distances[destX][destY]<<endl;
			}
			else
				cout<<"NO"<<endl;
		}	
	}
