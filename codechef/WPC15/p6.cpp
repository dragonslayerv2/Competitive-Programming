#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	char matrix[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>matrix[i][j];
	
	int distinctCount[n][n][26]={0};

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			distinctCount[i][j][matrix[i][j]-'A']++;
			
			if(i>0)
				for(int k=0;k<26;k++)
					distinctCount[i][j][k]+=distinctCount[i-1][j][k];
			if(j>0)
				for(int k=0;k<26;k++)
					distinctCount[i][j][k]+=distinctCount[i][j-1][k];
			
			if(i>0&&j>0)
				for(int k=0;k<26;k++)
					distinctCount[i][j][k]-=distinctCount[i-1][j-1][k];
		}
	
	for(int left=0;left<n;left++){
		
	}
}
