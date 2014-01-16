#include<stdio.h>
#include<string.h>

//------------------------------------------------------------------------------
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

inline int readInt() 
{
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c=='\n'||c==' ') break;
                              n = n * 10 + c - '0';
    }
    return n;
}
 

inline void writeInt(int x) 
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
//------------------------------------------------------------------------------


#define MAX 100000

int flags[MAX/32+2];

#define isSet(n) flags[n>>5]&(1<<(n&31))
#define unset(n) flags[n>>5] &= ~(1<<(n&31))
#define set(n) flags[n>>5]|=(1<<(n&31))

#define MOD (1000000007)




long long p(int m)
{
    if(m==0) return 1;
    
    long long x=p(m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*26)%MOD;
}




inline int disjoint(int n)
{
       memset(flags,-1,sizeof(flags));
       
       int count=0;
       int c=n%2-1;
       int i;
       for(i=1;i<=n;i++)
       {
               if(isSet(i))
               {
                           int x=i;
                           
                            while(isSet(x))
                            {
                             //        printf("%d ",x);
                                      unset(x);
                                      x=x>n/2?2*x-n+c:2*x;       
                            }
                            count++;            
                           // printf("c=%d\n", count);
               }        
       }
       return count;
}      
int main()
{
    int t;
    t=readInt();
    while(t--)
    {
           int n;
           n=readInt();
           writeInt((int)p(disjoint(n)));
    }        
    return 0;
}
