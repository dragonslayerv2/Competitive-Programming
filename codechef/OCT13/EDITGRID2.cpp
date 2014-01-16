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
	stream<<" "<<O.r1;
	stream<<" "<<O.c1;
	if(O.op==1)
	{
		stream<<" "<<O.r2;
		stream<<" "<<O.c2;
	}
	return stream;
}


void generateoperations(vector<operation> &operations,int pos1,int pos2,int column)
{
//	cout<<"Generate operations"<<endl;
//	cout<<"Moving "<<pos1<<" to "<<pos2<<endl;
	
	for(int i=pos2;i>pos1;i--)
	{
		operations.push_back(operation(1,i,column+1,i+1,column+1));
	//	cout<<"Move "<<i
	}
		
}
int main()
{
//	freopen("test.txt","r",stdin);
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
		//	cout<<"Checking for column"<<j<<endl;
			int blackpos=0;
			while(blackpos<n&&GRID[blackpos][j]=='B')
				blackpos++;
//			cout<<"got blackpos = "<<blackpos<<endl;
			if(blackpos==n)
				operations.push_back(operation(3,n,j+1));
			else if(blackpos==0)
				operations.push_back(operation(2,1,j+1));
			
			else
			{
				int save=blackpos-1;
				while(blackpos<n)
				{
					save=save+1;
					blackpos++;
					
					
					while(blackpos<n&&GRID[blackpos][j]=='W')
						blackpos++;
//					cout<<"Got new blackpos = "<<blackpos<<endl; 
					if(blackpos==n)
						break;
					else
					{
//						cout<<"Generating moves"<<endl;
						generateoperations(operations,save,blackpos,j);
					}
	
				}
			}
		}
		cout<<operations.size()<<endl;
		for(int i=0;i<operations.size();i++)
			cout<<operations[i]<<endl;
	}
}
