#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<char> > grid(n,vector<char>(n));
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>grid[i][j];
		vector<vector<bool> > southRock(n,vector<bool>(n));
		vector<vector<bool> > eastRock(n,vector<bool>(n));
		
		for(int i=0;i<n;i++){
			southRock[n-1][i]=(grid[n-1][i]=='#');
			eastRock[i][n-1]=(grid[i][n-1]=='#');
		}
		
		for(int i=n-2;i>=0;i--){
			for(int j=n-1;j>=0;j--){
				southRock[i][j]=(southRock[i+1][j]||(grid[i][j]=='#'));
				
			}		
		}
		for(int i=n-1;i>=0;i--){
			for(int j=n-2;j>=0;j--){
				eastRock[i][j]=(eastRock[i][j+1]||(grid[i][j]=='#'));
				
			}		
		}
		
		
		int count=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				count+=(!(southRock[i][j]||eastRock[i][j]));
			}
		cout<<count<<endl;
	}
}
