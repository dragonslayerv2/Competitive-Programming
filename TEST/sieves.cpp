#include <cstdio>

#define MAX 5000001
#define MOD 1000000007

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

    return 0;

}
