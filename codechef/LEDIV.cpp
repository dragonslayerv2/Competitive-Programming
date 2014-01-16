#include<stdio.h>
#include<math.h>

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
     if(x==-1)
     {
              PUTCHAR('-');
              PUTCHAR('1');
              PUTCHAR('\n');
     }
     else
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
}
inline int gcf(int a, int b)
{
   int temp;    
   while(b)
   {
           temp=a;          
           a=b;
           b=temp%b;
   }
   return a;
}



#define MAX 100001

int b[MAX];
inline int initialise()
{
       b[1]=-1;
       int i,j;
       for(i=2;i<MAX;i++)
               b[i]=i;
       int k=sqrt(MAX);
       for(i=2;i<=k;i++)
       {
                        if(b[i]==i)
                        {
                                   for(j=i*i;j<MAX;j+=i)
                                   {
                                           if(b[j]==j)
                                                      b[j]=i;
                                   }
                        }
       }
}

int main()
{
    initialise();
    int t,i;
    t=readInt();
    while(t--)
    {
              int n,g;
              n=readInt();
              int flag=1;
              g=readInt();
              for(i=1;i<n;i++)
              {
                                      
                                      g=gcf(g,readInt());
                                      
                                      if(g==1) break;         
              }
              i++;
              for(;i<n;i++)
                           readInt();
              writeInt(b[g]);
    }
    return 0;
}
