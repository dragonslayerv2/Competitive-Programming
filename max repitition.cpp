#include<stdio.h>
#include<string.h>
#define MAX 10001
#define MAXFLAGS MAX/32+1

int flags[MAXFLAGS];

#define isSet(n) flags[n>>5]&(1<<(n&31))
#define unset(n) flags[n>>5] &= ~(1<<(n&31))
#define set(n) flags[n>>5]|=(1<<(n&31))

#define GETCHAR getchar_unlocked
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
 


//------------------faster io --------------------------------------


int main()
{
   
    int t,n;
    t=readInt();
    int a[MAX];
    while(t--)
    {
              int i;
              memset(flags,-1,sizeof(flags));
              n=readInt();
              int max=0;
              int max_index=0;
              int c;
              for( i=0;i<n;i++)
              {       
                      c=readInt();
                      if(isSet(c))
                                   {
                                            unset(c);
                                            a[c]=1;
                                   }
                      else
                                   a[c]++;
                      if(a[c]==max)
                      {
                                   if(c<max_index)
                                                  max_index=c;
                      }
                      else if(a[c]>max)
                      {
                          max=a[c];
                          max_index=c;
                      }  
              }
     printf("%d %d\n",max_index,max);
    }
    return 0;
}
