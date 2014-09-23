#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<vector<char> > board(n,vector<char>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>board[i][j];
			
	bool flag = true;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			int count =0;
			if(i!=0)
				count+=(board[i-1][j]=='o');
			if(i!=n-1)
				count+=(board[i+1][j]=='o');
			if(j!=0)
				count+=(board[i][j-1]=='o');
			if(j!=n-1)
				count+=(board[i][j+1]=='o');
			if(count%2!=0){
				
				flag=false;
			}
			 	
		}
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
	
}
