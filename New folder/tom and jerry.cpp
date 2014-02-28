#include<iostream>
#include<vector>
using namespace std;

int count=0;
void solve(vector<vector<int> > &matrix,int currentX,int currentY)
{
	if(currentX<0||currentX>=matrix.size())
		return;
	if(currentY<0||currentY>=matrix.size())
		return;
	if(matrix[currentX][currentY]==1)
		return;
	else if(currentX==matrix.size()-1&&currentY==matrix.size()-1)
	{
		count++;
		return;
	}
	else
	{
		matrix[currentX][currentY]=1;
		solve(matrix,currentX+1,currentY);
		solve(matrix,currentX-1,currentY);
		solve(matrix,currentX  ,currentY+1);
		solve(matrix,currentX  ,currentY-1);
		matrix[currentX][currentY]=0;
	}
	
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int> > matrix(n,vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>matrix[i][j];
	
	solve(matrix,0,0);
	cout<<count;
}
