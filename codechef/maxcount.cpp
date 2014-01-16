#include<stdio.h>


#define GETCHAR getchar_unlocked

inline int readInt() 
{
    int x = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c=='\n'||c==' ') break;
                              x = x * 10 + c - '0';
    }
    return x;
}
 


//------------------faster io --------------------------------------


int main()
{
    int t,n;
    t=readInt();
    int a[10010];
    while(t--)
    {
              int i;
              for(i=1;i<=10001;i++)
                      a[i]=0;
              n=readInt();
              int max=0;
              int max_index=0;
              int c;
              
              for( i=0;i<n;i++)
              {       
                      c=readInt();
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
