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
int primecount[600]={0};
void generate_primes()
{
	for(int i=2;i<=500;i++)
	{
		bool isprime=true;
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				isprime=false;
				break;
			}
		}
		if(isprime)
			primecount[i]=1;
	}
	for(int i=1;i<=500;i++)
	{
		primecount[i]+=primecount[i-1];
	}
}


int main()
{
	generate_primes();
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
				int M;
				M=min(D[i][j],U[i][j]);
				M=min(M,L[i][j]);
				M=min(M,R[i][j]);
				count+=primecount[M];
			}
		}
		cout<<count<<endl;
	}
}
