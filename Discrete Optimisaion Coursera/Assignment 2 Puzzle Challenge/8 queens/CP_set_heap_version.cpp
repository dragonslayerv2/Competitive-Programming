#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
using namespace std;

//#define DEBUG

int n;								// size of board
vector<set<int> > domain;			// stores the value a particular column can take
vector<vector<int> > attacking;		// stores the number of queens attacking a particular cell
vector<int> column;					// decision variables
vector<int> propogateCaller;
list<int> single;
//prune the search space
inline void prune(int i,int j)
{
	// removing the cells on the same row from the search space
//	cout<<"Pruning \n";
	for(int column=0;column<n;column++)
		if(column!=j)
		{
//			cout<<"HRemoving "<<i<<" "<<column<<endl;
			if(attacking[i][column]==0)
				domain[column].erase(i);
			attacking[i][column]--;
		}
	
	//removing the cells on the same column from the search space 
	for(int row=0;row<n;row++)
		if(row!=i)
		{
//			cout<<"VRemoving "<<row<<" "<<j<<endl;
			if(attacking[row][j]==0)
				domain[j].erase(row);
			attacking[row][j]--;
		}
	
	//removing the diagnols
	for(int row=0;row<n;row++)
		if(row!=i)
		{
			int column=j+(row-i);
			if(column>=0&&column<n)
			{
//				cout<<"D1 Removing "<<row<<" "<<column<<endl;
				if(attacking[row][column]==0)
					domain[column].erase(row);
				attacking[row][column]--;
			}
			
			column=j-(row-i);
			if(column>=0&&column<n)
			{
//				cout<<"D 2 Removing "<<row<<" "<<column<<endl;
				if(attacking[row][column]==0)
					domain[column].erase(row);
				attacking[row][column]--;
			}
		}
	for(int i=0;i<n;i++)
		if(domain[i].size()==1&&column[i]==-1)
			single.push_back(i);
}
// revert the changes back done by placing the queen at cell i,j
inline void revert(int i,int j)
{
//	cout<<"removing "<<i<<" "<<j<<endl;
	//fixing the cells on the same row
	for(int column=0;column<n;column++)
		if(column!=j)
		{
			attacking[i][column]++;
			if(attacking[i][column]==0)
				domain[column].insert(i);
		}
	
	//fixing the cells on the same column
	for(int row=0;row<n;row++)
		if(row!=i)
		{
			attacking[row][j]++;
			if(attacking[row][j]==0)
				domain[j].insert(row);
			
		}
	
	//fixing the diagnols
	for(int row=0;row<n;row++)
		if(row!=i)
		{
			int column=j+(row-i);
			if(column>=0&&column<n)
			{
				attacking[row][column]++;
				if(attacking[row][column]==0)
					domain[column].insert(row);
			}
			
			column=j-(row-i);
			if(column>=0&&column<n)
			{
				attacking[row][column]++;
				if(attacking[row][column]==0)
					domain[column].insert(row);
			}
		}
}

void propogate(int caller)
{
//	cout<<"Propogating";
	while(single.size())
	{
		int j=single.front();
		if(column[j]==-1&&domain[j].size()==1)
		{
			int i=*domain[j].begin();
			propogateCaller[j]=caller;
			column[j]=i;
			prune(i,j);
					//debug();
		}
		single.pop_front();	
	}
}

bool solve(int currentColumn=0)
{
//	cout<<"Solving for "<<currentColumn<<endl;
	if(currentColumn==n)
		return true;
	
	if(column[currentColumn]!=-1) // if the current column is already solved using propogation move forward
	{
//		cout<<"Already Solved";
//		cout<<"Moving forwad";
		return solve(currentColumn+1);
		
	}
	
//	cout<<"trying for a possible solution "<<endl;
	for(set<int>::iterator i=domain[currentColumn].begin();i!=domain[currentColumn].end();i++)
	{
//		cout<<"Placing queen at "<<i<<" "<<currentColumn<<endl;
		column[currentColumn]=*i;			// place the queen at i,currentColumn
		prune(*i,currentColumn);				// prune the search space	
		propogate(currentColumn);						// propogate by continiously pruning
		//debug();
		if(solve(currentColumn+1)==true)	// try to solve for the next column
			return true;
//			cout<<"Solution not possible with "<<i<<" "<<currentColumn<<" reverting... "<<endl;
		revert(*i,currentColumn); 			// since the solution is not possible revert
		column[currentColumn]=-1;
			//debug();
			
//			cout<<"Reverting the changes due to propogation step"<<endl;
		for(int j=currentColumn+1;j<n;j++)  // reverting the changes due to propogation
			if(column[j]!=-1&&propogateCaller[j]==currentColumn)
			{
				propogateCaller[j]=-1;
//					cout<<"Unplacing the queen at "<<column[j]<<" "<<j<<endl;
				revert(column[j],j);
				column[j]=-1;
			}
	}
	return false;
//	cout<<"Solution not possible";
//	cout<<"Backtracking"<<endl;
}


int main(int argc,char *argv[])
{
	
	//cin>>n;
	sscanf(argv[1],"%d",&n);
	
	column.assign(n,-1);   // decision variables
	
	domain.resize(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			domain[i].insert(j);
		
	propogateCaller.assign(n,-1);
	attacking.assign(n,vector<int>(n,0)); // stores the number of queens attacking a (i,j) cell
	
	solve(); // solve the problem using constraint programming
	
	//output
	cout<<n<<endl;
	for(int i=0;i<column.size();i++)	
		cout<<column[i]<<" ";
}
