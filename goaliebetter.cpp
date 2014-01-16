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
    int t;
    t=readInt();
    while(t--)
    {
              int n;
              n=readInt();

       
       n = n|(n>>1);
       n = n|(n>>2);
       n = n|(n>>4);
       n = n|(n>>8);
       n = n|(n>>16);
       n = (n+1)>>1;
       writeInt(n);
       }
       return 0;
       
}
