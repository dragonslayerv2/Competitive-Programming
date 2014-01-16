#include<stdio.h>
#include<string.h>
#define MAX 101
#define MAXFLAGS MAX/32+1

int flags[MAXFLAGS];

#define isSet(n) flags[n>>5]&(1<<(n&31))
#define unset(n) flags[n>>5] &= ~(1<<(n&31))


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



//------------------faster io --------------------------------------


int main()
{
   
    int t,n,m;
    t=readInt();
    int a[MAX];
    while(t--)
    {
              int i;
              memset(flags,-1,sizeof(flags));
              n=readInt();
              m=readInt();
              
              int c,l;
              for( i=0;i<n;i++)
              {       
                      c=readInt();
                      l=readInt();
                      
                      if(isSet(l))
                                   {
                                            unset(l);
                                            a[l]=c;
                                   }
                      else
                                   a[l]+=c;  
                      
                      
              }
              
              for( i=0;i<m;i++)
              {       
                      
                      c=readInt();
                      l=readInt();
                      if(isSet(l))
                                   {
                                            unset(l);
                                            a[l]=(-1)*c;
                                   }
                      else
                                   a[l]-=c;  
                      

              }
              int count=0;
              
              for(i=1;i<=100;i++)
              {

                      if(!(isSet(i)))
                      {
                                   
                                   if(a[i]<0)
                                           count-=a[i];
                      }
              }
     writeInt(count);
    }
    return 0;
}
