#include<iostream>
#include<fstream>
#include<time.h>
#include<vector>
using namespace std;

int main(int argc,char *argv[])
{	
	if(argc==4)
	{
		ofstream log(argv[2]);
		for(int n=4;n<100;n++)	
		{
			char command[1000];
			// make the command format here.
			sprintf(command,"%s %d >%s",argv[1],n,argv[3]);
			
			// executing the process	
			clock_t start,end;
			start=clock();
			system(command);
			end=clock();
			double time=((double)(end-start))/CLK_TCK;
			// time now stores the time
		
			//get the input
			ifstream input(argv[3]);
			int N;
			input>>N;
			bool isOK=true;
			if(n!=N)
				isOK=false;
			else
			{	// write the verification code here
				vector<int> series(n);
				
				for(int i=0;i<n;i++)
					input>>series[i];
			
				vector<int> count(series.size());
				for(int i=0;i<series.size();i++)
					count[series[i]]++;
				bool isOK=true;
				for(int i=0;i<series.size();i++)
					if(count[i]!=series[i])
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
