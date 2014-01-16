
#include <cstdio>

#define MAX 5000001
#define MOD 1000000007

#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked


int readInt() 
{
    int n = 0;
    char c;
    while ((c = GETCHAR()) != '\n') 
    {
          n = n * 10 + c - '0';
    }
    return n;
}
 

void writeInt(int x) 
{
     int i = 10;
     char buf[11];

     buf[10] = '\n';
     while (x) 
     {
           buf[--i] = x % 10 + '0';
           x /= 10;
     }

     do 
     {
           PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}

char isprime[MAX];
long long answer[MAX];
#define true 't'
#define false 'f'
int count=1;
void sieve()
{
     int i,j;
     for(i=2;i<MAX;i++)
             isprime[i]=true;
     for(i=2;i*i<MAX;i++)
     {
             if(isprime[i]==false)
                                 continue;
             for(j=i*i;j<MAX;j+=i)
             {
                                  isprime[j]=false;
             }
     }
     answer[1]=1;
     for(i=2;i<MAX;i++)
     {
             if(isprime[i]==true) count++;
                           answer[i]=(answer[i-1]*count)%MOD;
     }
     
}



int main()
{
    
    sieve();
    int t=readInt();
    int n;
    while(t--)
    {
              n=readInt();
              
              writeInt((int)answer[n]);    
    }    
    return 0;
    
}
