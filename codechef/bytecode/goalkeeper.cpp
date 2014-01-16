#include<stdio.h>

int recurse(int n,int f,int i,int d)
{
        if (n==1)
       return i;
    else if(n%2==0)
    { 
                      if(f==0)
                              return recurse(n/2,f,i,d*2);
                      else
                              return recurse(n/2,f,i+d,d*2);
    }
    else
    {
                      if(f==0)
                              return recurse(n/2+1,1,i,d*2);
                      else
                              return recurse(n/2,0,i+d,d*2);
                              
    }
}
#define GETCHAR getchar//_unlocked
#define PUTCHAR putchar//_unlocked

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

int main()
{
    int t;
    t=readInt();
    while(t--)
    {
              int n;
              n=readInt();
              writeInt(recurse(n,0,1,1));
    }
    return 0;
}
