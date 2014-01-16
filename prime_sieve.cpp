#include<stdio.h>
#include<fstream>
using namespace std;

#include<conio.h>
#define MAX 5000001

bool isprime[MAX];


void sieve()
{
     int i,j;
     isprime[1]=0;
     for(i=2;i<MAX;i++)
             isprime[i]=true;
     for(i=2;i*i<MAX;i++)
     {
             if(isprime[i]==false)
                                 continue;
             for(j=i*i;j<MAX;j+=i)
                                  isprime[j]=false;
     }
}

int main()
{
    sieve();
    
	ofstream shobhit("shobhit.txt");
	shobhit<<"int prime[]={";
	for(int i=0;i<=10011;i++)
    {
		if(isprime[i])
			shobhit<<" "<<i<<",";
	}
	shobhit<<"};\n";
	shobhit<<"int semiprime={";
	for(int i=0;i<=10011;i+=2)
	{
		if(isprime[i/2])
			shobhit<<" "<<i<<",";
	}
	shobhit<<"};";
	printf("%d",isprime[103]);
    getchar();
    return 0;
}
