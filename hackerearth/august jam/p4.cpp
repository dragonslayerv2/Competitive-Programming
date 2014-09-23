#include<iostream>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

#define GETCHAR getchar


#define OBSTACLE "Obstacle"
#define LESS_PATHS "Not so many paths"

#define BLOCK 1000000
int readlong() 
{
	int flag=1;
    long long n = 0;
    char c;
    int sign=1;
    while (1)
    { 		
		c=GETCHAR();
		if(c=='#')
		{
			getchar();
			return BLOCK;
		}
    	if(c=='-')	sign=-1;
        else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
        else if(flag!=1) break; 
    }
    return sign*n;
}
#define K_MAX 101

int main(){
	//freopen("test4.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		vector<vector<int> > matrix(m,vector<int>(n));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				matrix[i][j]=readlong();
			}
		
		vector<vector<vector<int> > > paths(m,vector<vector<int> >(n));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				paths[i][j].reserve(K_MAX);
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				if(matrix[i][j]==BLOCK)
					continue;
				else if(i==0&&j==0){
					paths[i][j].push_back(matrix[0][0]);
				}
				else if(i==0){
					paths[i][j]=paths[i][j-1];
					for(int k=0;k<paths[i][j].size();k++)
						paths[i][j][k]+=matrix[i][j];
				}
				else if(j==0){
					paths[i][j]=paths[i-1][j];
					for(int k=0;k<paths[i][j].size();k++)
						paths[i][j][k]+=matrix[i][j];
				}
				else
				{
					merge(paths[i][j-1].begin(),paths[i][j-1].end(),paths[i-1][j].begin(),paths[i-1][j].end(),back_inserter(paths[i][j]));
					
					if(paths[i][j].size()==0)
						paths[i][j].clear();
					else{
						paths[i][j].resize(min((int)paths[i][j].size(),K_MAX));
						for(int k=0;k<paths[i][j].size();k++)
							paths[i][j][k]+=matrix[i][j];
					}
				}
			}
			
		int q;
		cin>>q;
		while(q--){
			int x,y,k;
			cin>>x>>y>>k;
			
			if(matrix[x][y]==BLOCK)	
				cout<<OBSTACLE;
			else if(paths[x][y].size()<k)
				cout<<LESS_PATHS;
			else
				cout<<paths[x][y][k-1];
			cout<<endl;
		}
	} 
}
