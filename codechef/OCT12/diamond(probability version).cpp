#include<stdio.h>

#define GETCHAR getchar//_unlocked


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


int powers[]={1,2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
#define MAX 5000


float recurse(int a[],int low,int high,int turn,int n)
{
     if(n==1)
             return (float)(a[low]+a[high])/2;

     if(turn>27||turn>n)
             return 0;
     
     return ((float)(a[low]+a[high])/powers[turn]+ recurse(a,low,high-1,turn+1,n)+recurse(a,low+1,high,turn+1,n));
}

int main()
{
    int t,n,i;
    int a[MAX];
    t=readInt();
    while(t--)
    {
              n=readInt();
              
              for(i=0;i<n;i++)
                              a[i]=readInt();              
              printf("%.3f\n",n%2?recurse(a,0,n-1,1,n/2+1):recurse(a,0,n-1,1,n/2));
    }
    return 0;
}
