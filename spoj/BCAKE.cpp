#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int r,c,k;
		cin>>r>>c>>k;
		
		vector<vector<char> > grid(r+1,vector<char>(c+1));
		vector<vector<int> > count(r+1,vector<int>(c+1));
		
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				cin>>grid[i][j];
		
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				count[i][j]=(grid[i][j]=='C')+count[i][j-1]+count[i-1][j]-count[i-1][j-1];
		
		bool flag=false;
		int MINarea=INT_MAX;
		
		for(int r1=1;r1<=r;r1++)
			for(int r2=r1;r2<=r;r2++)
				for(int c1=1;c1<=c;c1++)
					for(int c2=c1;c2<=c;c2++)
						if(count[r2][c2]-count[r1-1][c2]-count[r2][c1-1]+count[r1 - 1][c1 - 1]==k)
						{
							flag=true;
							MINarea=min(MINarea,(r2-r1+1)*(c2-c1+1));
						}	
		
		if(!flag)
			cout<<-1<<endl;
		else
			cout<<MINarea<<endl;
	}
}
