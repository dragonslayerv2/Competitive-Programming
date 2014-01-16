#include <iostream>
#include <csignal>
#include<cstdlib>
using namespace std;

void signalHandler( int signum )
{
    cout << "Interrupt signal (" << signum << ") received.\n";

    // cleanup and close up stuff here  
    // terminate program  
   

}


int main ()
{
    // register signal SIGINT and signal handler  
    signal(SIGSEGV, signalHandler);  
	int *a=0;
	*a=6;
	cout<<"hi..";
       return 0;
}
