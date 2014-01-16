#include<stdio.h>
#define MOD 1000000007

#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

int readInt() 
{
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c=='\n'||c==' ')break;
                              n = n * 10 + c - '0';
    }
    return n;
}
 

void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     // buf[10] = 0;
     buf[10] = '\n';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}

long long p(int n)
{
    if(n==0) return 1;
    
    if(n%2==0) 
    {
               long long x=p(n/2);
               return (x*x)%MOD;
    }
    else
    {
               long long x=p(n/2);
               return (x*x*2)%MOD;
    }
    
}
int main()
{
    int t=readInt();
    while(t--)
    {
              int n;
              n=readInt();
              int ans;
              if(n%2==0)
                        ans=(3*p(n/2)-2)%MOD;
              else
                        ans=(4*p((n-1)/2)-2)%MOD;
              writeInt(ans);
    }
    return 0;
}
