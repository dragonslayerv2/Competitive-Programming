	#include<iostream>
	#include<vector>
	using namespace std;
	
	int main()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			vector<vector<char> > board(n,vector<char>(n));
			for(int i=0;i<board.size();i++)
				for(int j=0;j<board[i].size();j++)
					cin>>board[i][j];
			
			vector<vector<int> > DP(n,vector<int>(n));
			bool flag=true;
			int ans=0;
			for(int j=board.size()-1;j>=0;j--)
			{
				if(!flag)
					break;
				for(int i=board.size()-1;i>=0;i--)
				{
					if(i+2<n&&j+1<n)
						DP[i][j]=max(DP[i][j],DP[i+2][j+1]);
					if(i-2>=0&&j+1<n)
						DP[i][j]=max(DP[i][j],DP[i-2][j+1]);
					if(i+1<n&&j+2<n)
						DP[i][j]=max(DP[i][j],DP[i+1][j+2]);
					if(i-1>=0&&j+2<n)
						DP[i][j]=max(DP[i][j],DP[i-1][j+2]);
					
					if(board[i][j]=='P')
						DP[i][j]++;
					
					if(board[i][j]=='K')
					{
						ans=DP[i][j];
						flag=false;
						break;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
