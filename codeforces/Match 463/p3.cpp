#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<long long> > a){
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
int main(){
//	freopen("testC.txt","r",stdin);
	int n;
	cin>>n;
	vector<vector<long long> > board(n,vector<long long>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>board[i][j];
	
	vector<vector<long long> > upLeft(n,vector<long long>(n)); 
	vector<vector<long long> > upRight(n,vector<long long>(n)); 
	vector<vector<long long> > downLeft(n,vector<long long>(n)); 
	vector<vector<long long> > downRight(n,vector<long long>(n)); 
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			upLeft[i][j]=upRight[i][j]=board[i][j];
			if(i-1>=0&&j-1>=0)
				upLeft[i][j]+=upLeft[i-1][j-1];
			if(i-1>=0&&j+1<n)
				upRight[i][j]+=upRight[i-1][j+1];
			
		}	
	
	for(int i=n-1;i>=0;i--)
		for(int j=0;j<n;j++){
			downLeft[i][j]=downRight[i][j]=board[i][j];
			if(i+1<n&&j-1>=0)
				downRight[i][j]+=downRight[i+1][j-1];
			if(i+1<n&&j+1<n)
				downLeft[i][j]+=downLeft[i+1][j+1];
		}
		
	pair<int,int> white;
	pair<int,int> black;
	long long ansWhite = 0;
	long long ansBlack = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			long long currentAns=0;
			currentAns=upLeft[i][j]+upRight[i][j]+downLeft[i][j]+downRight[i][j];
			currentAns-=3*board[i][j];
			if((i+j)%2==0)
			{
				if(ansWhite<currentAns)
				{
					ansWhite=currentAns;
					white=make_pair(i+1,j+1);
				}
			}
			else
			{
				if(ansBlack<currentAns)
				{
					ansBlack=currentAns;
					black=make_pair(i+1,j+1);
				}
			}
		}
	cout<<ansWhite+ansBlack<<endl;
	cout<<white.first<<" "<<white.second<<" "<<black.first<<" "<<black.second;
}
