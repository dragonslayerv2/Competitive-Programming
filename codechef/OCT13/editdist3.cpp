#include<iostream>
#include<vector>
using namespace std;

class operation
{
	int op;
	int r1,r2,c1,c2;
	public:
		operation(int OP,int R1,int C1,int R2=0,int C2=0)
		{
			op=OP;
			r1=R1;
			r2=R2;
			c1=C1;
			c2=C2;
		}
		friend ostream & operator <<(ostream &,operation&);
};

ostream & operator <<(ostream &stream,operation &O)
{
	stream<<O.op;
	stream<<" "<<O.r1+1;
	stream<<" "<<O.c1+1;
	if(O.op==1)
	{
		stream<<" "<<O.r2+1;
		stream<<" "<<O.c2+1;
	}
	return stream;
}
int generatesequence(vector<operation>& operations,int column,int row1,int row2)
{
	int cost=0;
	for(int i=row1;i>row2;i--)
	{
		operations.push_back(operation(1,i-1,column,i,column));
		cost++;
	}
	return cost;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,c2,c3;
		cin>>n>>m>>c2>>c3;
		
		vector<vector<char> > GRID(n,vector<char>(m));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>GRID[i][j];
			
		vector<operation> operations;	
		for(int j=0;j<m;j++)
		{
			
			vector<int> blackrows;
			for(int i=0;i<n;i++)
				if(GRID[i][j]=='B')
					blackrows.push_back(i);
			
			if(!blackrows.size())
				operations.push_back(operation(2,0,j));
			else if(blackrows.size()==n)
				operations.push_back(operation(3,n-1,j));
			else
			{
				vector<operation> tempoperations;
				int cost=0;
				for(int i=0;i<blackrows.size();i++)
					cost+=generatesequence(tempoperations,j,blackrows[i],i);
				
				if(cost>c2*blackrows.size())
				{
					for(int i=0;i<blackrows.size();i++)
						operations.push_back(operation(3,blackrows[i],j));
				
						operations.push_back(operation(2,0,j));
				}
				
				else 
				{
					for(int i=0;i<tempoperations.size();i++)
						operations.push_back(tempoperations[i]);
				}	
			}
		}
			
		cout<<operations.size()<<endl;
		for(int i=0;i<operations.size();i++)
			cout<<operations[i]<<endl;
	}
}
