#include<iostream>
#include<vector>
using namespace std;


template<class T> void debug(const T &a)
{
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<a[i].size();j++)
			cout<<a[i][j];
		cout<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		vector<vector<char> > maze(r,vector<char>(c));
		
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>maze[i][j];
				
		vector<vector<int> >L(r,vector<int>(c));
		vector<vector<int> >R(r,vector<int>(c));
		vector<vector<int> >U(r,vector<int>(c));
		vector<vector<int> >D(r,vector<int>(c));
		
		
		// calculate L
		for(int i=0;i<r;i++)
		{
			long long streak=0;
			for(int j=0;j<c;j++)
			{
				if(maze[i][j]=='#')
					streak=0;
				L[i][j]=streak;
				if(maze[i][j]=='^')
					streak++;
			}
		}
		//debug(L);
		
		//calculate R
		for(int i=0;i<r;i++)
		{
			long long streak=0;
			for(int j=c-1;j>=0;j--)
			{
				if(maze[i][j]=='#')
					streak=0;
				R[i][j]=streak;
				if(maze[i][j]=='^')
					streak++;
			}
		}
		
		//debug(R);
		//calculate U
		for(int i=0;i<c;i++)
		{
			long long streak=0;
			for(int j=0;j<r;j++)
			{
				if(maze[j][i]=='#')
					streak=0;
				U[j][i]=streak;
				if(maze[j][i]=='^')
					streak++;
			}
		}
		//debug(U);
		//calcualte D
		
		for(int i=0;i<c;i++)
		{
			long long streak=0;
			for(int j=r-1;j>=0;j--)
			{
				if(maze[j][i]=='#')
					streak=0;
				D[j][i]=streak;
				if(maze[j][i]=='^')
					streak++;
			}
		}
		//debug(D);
		long long count=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(D[i][j]>=2&&U[i][j]>=2&&L[i][j]>=2&&R[i][j]>=2)
					count++;
				
			}
		}
		
		cout<<count<<endl;
	}
}
