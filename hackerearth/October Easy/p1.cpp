#include<iostream>
using namespace std;

int main(){
	bool isWin[101][101][101]={false};
	
	
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			for(int k=0;k<101;k++){
				if(i==0&&j==0&&k==0)
					continue;
				
				bool otherLose=false;
				for(int p=0;p<=1;p++)
					for(int q=0;q<=1;q++)
						for(int r=0;r<=1;r++){
							if(!p&&!q&&!r){
								continue;
							}
							if(i-p>=0&&j-q>=0&&k-r>=0){
								if(!isWin[i-p][j-q][k-r]){
									otherLose=true;
									break;
								}
							}
						}
				isWin[i][j][k]=otherLose;
			}
	
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		cout<<(isWin[a][b][c]?"Ashima":"Aishwarya")<<endl;
	}
				
}
