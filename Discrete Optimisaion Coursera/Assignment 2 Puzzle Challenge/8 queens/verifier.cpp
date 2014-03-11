#include<iostream>
#include<fstream>
#include<time.h>
#include<vector>
using namespace std;

vector<vector<bool> > board;

int main(int argc,char *argv[])
{
	
	if(argc==3)
	{
		ofstream log(argv[2]);
		for(int n=4;n<100;n++)	
		{
			cout<<"---------------------------------"<<endl;
			char command[1000];
			sprintf(command,"%s %d",argv[1],n);
			clock_t start,end;
			start=clock();
			system(command);
			end=clock();
			double time=((float)(end-start))/CLK_TCK;
			cout<<endl<<time<<endl;
			log<<n<<" "<<time<<endl;
			log.flush();
			cout<<"-----------------------------------------"<<endl;
		}
	}
}
