#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int> > lasers;
vector<pair<int,int> > enemies;

#define LEFT 0
#define RIGHT 1
#define UP 2

bool solve(int pos,int enemiesCount){
	if(!enemiesCount)
		return true;
	if(pos==lasers.size()){
		return (!enemiesCount);
	}
	else{
		bool ans = false;	
		for(int i=0;i<3;i++){
			//updation
			int killedCount=0;
			for(int j=0;j<enemiesCount-killedCount;j++)
			{
				bool killed = false;			
				switch(i){
					case LEFT: if((enemies[j].first==lasers[pos].first)&&(enemies[j].second<lasers[pos].second)) killed=true; break;
					case RIGHT: if((enemies[j].first==lasers[pos].first)&&(enemies[j].second>lasers[pos].second)) killed=true; break;
					case UP: if((enemies[j].first<lasers[pos].first)&&(enemies[j].second==lasers[pos].second)) killed=true; break;
				}	
				// removeing an enemy
				if(killed){
					swap(enemies[j],enemies[enemiesCount-killedCount-1]);
					killedCount++;
					j--;
				}
			}
			//updation ends				
			ans=(ans||solve(pos+1,enemiesCount-killedCount));
		}
		return ans;
	}
}


int main(){
//	freopen("testSHOOTING.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		lasers.clear();
		enemies.clear();
		vector<int> row(n+1);
		vector<int> column(m+1);
			
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				char c;
				cin>>c;
				if(c=='E')
					enemies.push_back(make_pair(i,j));
				else if(c=='L')
				{
					lasers.push_back(make_pair(i,j));	
					row[i]=1;
					column[j]=1;
				}
			}
			
		bool flag=true;
		
		for(int i=0;i<enemies.size();i++)
			if(!row[enemies[i].first]&&!column[enemies[i].second])
				flag = false;
		
		vector<int> kill(enemies.size());
		
		for(int i=0;i<enemies.size();i++)
			for(int j=0;j<lasers.size();j++)
				if((enemies[i].first<lasers[j].first)&&(enemies[i].second==lasers[j].second))
				   kill[i]++;
				else if(enemies[i].first==lasers[j].first)
					kill[i]++;
		
		int ctr=0;
		while(ctr)
		{
		ctr=0;
		for(int i=0;i<kill.size();i++)
			if(!kill[i])
			{
				flag=false;
			}
		for(int i=0;i<kill.size();i++)
			if(kill[i]==1)
			{
				int j;
			 for(j=0;j<lasers.size();j++)
				if((enemies[i].first<lasers[j].first)&&(enemies[i].second==lasers[j].second))
				   break;
				else if(enemies[i].first==lasers[j].first)
					break;
			 
			 
			 if((enemies[i].first<lasers[j].first)&&(enemies[i].second==lasers[j].second))
			 		for(int k=0;k<lasers[j].first;k++)	 
					    {
					    	swap(enemies[i],enemies[enemies.size()-1]);
					    	swap(kill[i],kill[enemies.size()-1]);
					    	enemies.pop_back();
					    	kill.pop_back();
					    	i--;
					    } 
			}
		}
		if(flag&&solve(0,enemies.size()))
			cout<<"Possible";
		else
			cout<<"Impossible";
		cout<<endl;
	}
}	
