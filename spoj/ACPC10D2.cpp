#include<iostream>
#include<limits>
#include<vector>
using namespace std;

vector<vector<int> > solution;
vector<vector<bool> > exist;
long long solve(vector<vector<int> > &matrix,int i=0,int j=1)
{
	
	if(i>=matrix.size())
		return 1000000000000LL;
	if(i==matrix.size()-1&&j==1)
		return matrix[i][j];
	if(!exist[i][j])
	{
		exist[i][j]=true;
		if(j==0)
			solution[i][j]= matrix[i][j]+min(solve(matrix,i+1,j),min(solve(matrix,i+1,j+1),solve(matrix,i,j+1)));
		else if(j==1)
			solution[i][j]= matrix[i][j]+min(solve(matrix,i+1,j-1),min(solve(matrix,i+1,j),min(solve(matrix,i+1,j+1),solve(matrix,i,j+1))));
		else
			solution[i][j]= matrix[i][j]+min(solve(matrix,i+1,j),solve(matrix,i+1,j-1));			
	}
	return solution[i][j];
}
int main()
{
	int T=1;
	while(1)
	{	
		exist.clear();
		solution.clear();
		int n;
		cin>>n;
		if(n==0)
			break;
		vector<vector<int> > matrix(n,vector<int>(3));
		solution.resize(n,vector<int>(3));
		exist.resize(n,vector<bool>(3));
	
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				cin>>matrix[i][j];
		
		cout<<T<<". "<<solve(matrix)<<endl;
		T++;
	}
}

