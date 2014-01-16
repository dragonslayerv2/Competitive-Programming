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
     buf[10] = ' ';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != ' ');
}
//------------ faster i/o-------
int gcf(int a, int b)
{
   if (b==0) return a;
   return gcf(b,a%b);
}

int main()
{
    int t,n,a[50],i,g;
    t=readInt();
    while(t--)
    {
              n=readInt();
              
              a[0]=readInt();
              a[1]=readInt();
              g=gcf(a[0],a[1]);
              for(i=2;i<n;i++)
              {
                              a[i]=readInt();
                              g=gcf(g,a[i]);
              }
              for(i=0;i<n;i++)
              {
                              writeInt(a[i]/g);
              }
              PUTCHAR('\n');
    }
    return 0;
}
