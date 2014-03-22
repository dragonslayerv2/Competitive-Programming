#include<iostream>
#include<vector>
using namespace std;

const int EMPTY = -1;

int 
int main(int argc,char *argv[])
{
	vector<vector<int> >  board       (9,vector<int>(9));
	vector<vector<bool> > rowDomain   (9,vector<bool>(9,true));
	vector<vector<bool> > columnDomain(9,vector<bool>(9,true));
	vector<vector<bool> > squareDomain(9,vector<bool>(9,true));
	
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			cin>>board[i][j];
			board[i][j]--;
		
			row[i][board[i][j]]   =false; //removing the cell from the row domain
			column[j][board[i][j]]=false;
			sq	
		}
	
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cout<<board[i][j]<<"\t";
		cout<<endl;
	}
}
