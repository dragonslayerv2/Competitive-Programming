#include<iostream>
#include<cstdlib>
#include<time.h>
#include<vector>
using namespace std;

vector<vector<char> > color;
int n,m;
void removeLeft(int maxX,int maxY){
	for(int j=maxY-1;j>=0&&color[maxX][j]=='W';j--)
		color[maxX][j]='B';
	for(int j=maxY+1;j<n&&color[maxX][j]=='W';j++)
		color[maxX][j]='B';
	color[maxX][maxY]='B';
}
void removeUp(int maxX,int maxY){
	for(int i=maxX-1;i>=0&&color[i][maxY]=='W';i--)
		color[i][maxY]='B';
	for(int i=maxX+1;i<n&&color[i][maxY]=='W';i++)
		color[i][maxY]='B';
	color[maxX][maxY]='B';
}

#define LEFT 0
#define UP 1

#define make_query(x,y,d) make_pair(make_pair(x,y),d)

int main(){
	freopen("test.txt","r",stdin);
	srand(time(NULL));
	int k;
	cin>>n>>m>>k;
	color.assign(n,vector<char>(m,'W'));
	for(int i=0;i<k;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		color[x][y]='B';
	}	
	
	vector<pair<pair<int,int>,int> > Q; 
	vector<pair<int,int> > whites;
	while(1){
		whites.clear();
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(color[i][j]=='W')
					whites.push_back(make_pair(i,j));
		
		if(!whites.size())
			break;
		else{
			int pos=rand()%whites.size();
			int dir=rand()%2;
			Q.push_back(make_query(whites[pos].first,whites[pos].second,dir));
			if(dir==UP)
				removeUp(whites[pos].first,whites[pos].second);
			else
				removeLeft(whites[pos].first,whites[pos].second);
		}
	}
	
	cout<<Q.size()<<endl;
	for(int i=0;i<Q.size();i++)
		cout<<Q[i].first.first+1<<" "<<Q[i].first.second+1<<" "<<Q[i].second<<endl;
}
