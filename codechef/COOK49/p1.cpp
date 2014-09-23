#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		bool rowLasers[100];
		bool columnLasers[100];
		for(int i=0;i<n;i++)
			rowLasers[i]=false;
		for(int i=0;i<m;i++)
			columnLasers[i]=false;
			
		vector<pair<int,int> > enemies;
		enemies.reserve(n*m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				char c;
				cin>>c;
				if(c=='E')
					enemies.push_back(make_pair(i,j));
				else if(c=='L'){
					rowLasers[i]=true;
					columnLasers[j]=true;
				}
			}
		
		bool left = false;
		for(int i=0;i<enemies.size();i++)
			if(!rowLasers[enemies[i].first]&&!columnLasers[enemies[i].second]){
				cout<<i<<" left";
				left=true;
			}
				
		if(!left)
			cout<<"Possible"<<endl;
		else
			cout<<"Impossible"<<endl;
			
	}
}
