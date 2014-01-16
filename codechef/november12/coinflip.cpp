// Normally wouldn't bother with this, but there's a lot of data to read so we need to be fast.
#include<stdio.h>
#define GETCHAR getchar
#define PUTCHAR putchar

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
    int T=readInt();
    while(T--)
    {
              int G;
              int I,N,Q;
              G=readInt();
              while(G--)
              {
                        I=readInt();
                        N=readInt();
                        Q=readInt();
                        
                        writeInt(Q==I?N/2:(N-(N/2)));
              }        
    }
    return 0;
}
