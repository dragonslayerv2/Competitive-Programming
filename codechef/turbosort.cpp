#include<stdio.h>
#include<string.h>
#define MAX 1000010
#define MAXFLAGS MAX/32+1

int flags[MAXFLAGS];

#define isSet(n) (flags[n>>5]&(1<<(n&31)))
#define unset(n) (flags[n>>5] &= ~(1<<(n&31)))
#define set(n) (flags[n>>5]|=(1<<(n&31)))

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

//------------------faster io --------------------------------------


int main()
{
              int a[MAX];   
              int i,j,n;
              memset(flags,-1,sizeof(flags));
              n=readInt();
              int c;
              for(i=0;i<n;i++)
              {       
                      c=readInt();
                      if(isSet(c))
                                   {
                                            unset(c);
                                            a[c]=1;
                                   }
                      else
                                   a[c]++;
              }  
              for(i=0;i<MAX;i++)
              {
                      if(!isSet(i))
                      {
                                   for(j=0;j<a[i];j++)
                                                      writeInt(i);
                      }
              }

    
    return 0;
}
