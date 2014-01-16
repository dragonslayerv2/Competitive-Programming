#include <stdio.h>

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

bool isprime[MAX];
int answer[MAX];

int count=1;
void sieve()
{
      int i,j;
    memset(isprime,-1,sizeof(isprime));
    unset(0);
    unset(1);
    unset(4);

    for(i=6;i<=MAX;i+=6)
    {
            unset(i);
            unset(i+2);
            unset(i+3);
            unset(i+4);
    }
    for(i=5;i*i<=MAX;i+=2)
                          if(isSet(i))
                          {
                                        for(j=i*i;j<=MAX;j+=i)
                                                unset(j);
                          }
     answer[1]=1;
     for(i=2;i<MAX;i++)
     {
             if(isprime[i]) count++;
             
             answer[i]=(int)(((long long)answer[i-1]*count)%MOD);              
     }
     
}



int main()
{
    
    sieve();
    int t,n;
    t=readInt();
   // scanf("%d",&t);
    while(t--)
    {
             n=readInt();
             // scanf("%d",&n);
            // writeInt((int)answer[n]);    
            printf("%d\n",answer[n]);
    } 
    return 0;
}
