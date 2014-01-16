#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int flags[1000/32+2];

#define isSet(n) flags[n>>5]&(1<<(n&31))
#define unset(n) flags[n>>5] &= ~(1<<(n&31))
#define set(n) flags[n>>5]|=(1<<(n&31))

int count;

inline void reset()
{
       count=0;
       memset(flags,0,sizeof(flags));
}
inline void check(int num)
{
       if(isSet(num))
       {
                     unset(num);
                     count--;
       }
       else
       {
                     set(num);
                     count++;
       }
}

int main()
{
    int n,k,i,num;
    scanf("%d %d",&n,&k);
    reset();
    char string[100];
    while(k--)
    {
              scanf("%s",string);
              if(string[2]=='I')
              {
                  scanf("%d",&num);
                  check(num);
              }                                           
              else
                  reset();              
              printf("%d\n",count);
    }
    return 0;
}
