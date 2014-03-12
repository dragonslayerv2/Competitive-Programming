#include<iostream>
#include<fstream>
#include<time.h>
#include<vector>
using namespace std;

vector<int> board;

#define isSafe(x1,y1,x2,y2) (x1!=x2&&y1!=y2&&(y1-y2)!=(x1-x2)&&(y1-y2)!=(x2-x1))
int main(int argc,char *argv[])
{
	
	if(argc==4)
	{
		ofstream log(argv[2]);
		for(int n=4;n<100;n++)	
		{
			char command[1000];
			sprintf(command,"%s %d >%s",argv[1],n,argv[3]);
		
		
			clock_t start,end;
			start=clock();
			system(command);
			end=clock();
			double time=((double)(end-start))/CLK_TCK;

		
			ifstream input(argv[3]);
			int N;
			input>>N;
			bool isOK=true;
			if(n!=N)
				isOK=false;
			else
			{
				board.resize(n);
				for(int i=0;i<n;i++)
					input>>board[i];
				
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						if(i!=j)
							if(!isSafe(i,board[i],j,board[j]))
								isOK=false;
			}

			cout<<n<<"\t=>\t";
			log <<n<<"\t=>\t";
			if(isOK)
			{
				cout<<"Verified OK\t"<<time<<endl;
				log<<"Verified OK\t"<<time<<endl;
				log.flush();
			}
			else
			{
				cout<<"Wrong answer"<<endl;
				log <<"Wrong answer"<<endl;
			}
				
			cout<<"-----------------------------------------"<<endl;
			log <<"-----------------------------------------"<<endl;
		}
	}
	else 
		cout<<"Usage: verifier [exec_file_name] [log_file_name] [output_dmp_file]\n";
}
