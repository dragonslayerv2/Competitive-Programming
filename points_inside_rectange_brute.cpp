#include<iostream>
#include<vector>
using namespace std;


int main(){
	//freopen("rectTest.txt","r",stdin);
	vector<vector<int> > board(1000,vector<int>(1000,0));
	int q;
	cin>>q;
	while(q--){
		char type;
		cin>>type;
		int x,y;
		cin>>x>>y;
		switch(type){
			case 'I': board[x][y]++;
				break;
			case 'D': board[x][y]--;
				break;
			case 'Q':
					int sum=0;
					for(int i=0;i<=x;i++)
						for(int j=0;j<=y;j++)
							sum+=board[i][j];
					
					cout<<sum<<endl;
				break;
		}
	}
}
