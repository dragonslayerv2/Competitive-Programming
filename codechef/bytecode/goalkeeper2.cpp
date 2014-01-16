#include<stdio.h>


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

int main()
{
    int T,N,n,i;
    T=readInt();
    while(T--)
    {
      N=readInt();
      i=1;
      n=N;     
      while(n)
      {
             n>>=1;
             i<<=1;       
      }
      i>>=1;
      writeInt((N-i)*2+1);
    }
    return 0;
}
