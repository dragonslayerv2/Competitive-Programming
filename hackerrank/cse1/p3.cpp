#include<iostream>
#include<vector>
using namespace std;

#define INVALID 10000000
int n,m;
int solution[20][1200000];
bool calculated[20][1200000];
vector<vector<int> > cost;

int solve(int gi,int taken){
	if(gi==n)
		return 0;
	else{
		if(!calculated[gi][taken]){
			calculated[gi][taken]=true;
			solution[gi][taken]=INVALID;	
			for(int i=0;i<m;i++){
				if(!(taken&(1<<i))){
					int sum=0;
					for(int j=gi;j<n;j++){
						sum+=cost[i][gi];
						int newValue=sum+solve(i+1,taken|(1<<i));
						solution[gi][taken]=min(solution[gi][taken],newValue);	
					}
					
					
				}
			}
			return solution[gi][taken];
		}
	}
}

int main(){	
freopen("test.txt","r",stdin);
	cin>>n>>m;
	cost.resize(m,vector<int> (n));
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>cost[i][j];
	
	
	 
	cout<<solve(0,0);
}
