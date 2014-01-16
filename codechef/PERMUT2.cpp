#include<stdio.h>
#define MAX 100010

#define GETCHAR getchar_unlocked
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


int main()
{
    int n,i,flag;
    int a[MAX];
    while(1)
    {
            
            n=readInt();
            if(n==0) break;
            flag=0;
            for(i=1;i<=n;i++)
            {
                    a[i]=readInt();
            }
            for(i=1;i<=n;i++)
            {
                    if(i!=a[a[i]])
                                  flag=1;
                                  
            }
            printf("%s\n",flag?"not ambiguous":"ambiguous");
    }
    return 0;
}
