#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10000010
#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));

int isprime[MAX/32+2];
int primes[MAX];



void sieve()
{
    int i,j;
    memset(isprime,-1,sizeof(isprime));
    unset(0);
    unset(1);
    unset(4);

    for(i=6;i<=MAX;i+=6)
    {

            unset(i);
            unset(i+2);
            unset(i+3);
            unset(i+4);
    }
    for(i=5;i*i<=MAX;i+=2)
                           if(isSet(i))
                             {
                                        for(j=i*i;j<MAX;j+=i)
                                                unset(j);
                             }
    int count=0;
    for(i=0;i<MAX;i++)
    {
        if(isSet(i))
        {
            primes[i]=count;
            count++;
        }
    }
}
#define EVEN 0
#define ODD 3

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
void hackgrid(int a[500][500],int i,int j,int type)
{

    if(a[i][j]==-1) return;
    if(type==EVEN)
    {
        if((!(a[i][j]%2))&&a[i][j]!=2)
        {
            a[i][j]=-1;
           // printf("Hacking %d %d\n",i,j);
            hackgrid(a,i+1,j,type);
            hackgrid(a,i-1,j,type);
            hackgrid(a,i,j+1,type);
            hackgrid(a,i,j-1,type);
        }
    }
    else
    {
        if(!(isSet(a[i][j]))&&a[i][j]%2)
        {
           // printf("Hacking %d %d\n",i,j);
            a[i][j]=-1;
            hackgrid(a,i+1,j,type);
            hackgrid(a,i-1,j,type);
            hackgrid(a,i,j+1,type);
            hackgrid(a,i,j-1,type);
        }
    }
}
int main()
{
//   printf("%d",10000010);
    int i,j;
    int a[500][500];
    sieve();
    int t;
    t=readInt();
    while(t--)
    {
        int n;

        n=readInt();
        long long ans=0;
        for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=n+1;j++)
            {
                if(i==0||j==0||(i==n+1)||(j==n+1))
                        {a[i][j]=3;continue;}
                a[i][j]=readInt();
            }
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {

             //   printf("AT %d %d=>",i,j);
                if(a[i][j]==-1) continue;
                if(isSet(a[i][j]))
                {
                    ans+=primes[a[i][j]];
                }
                else
                {
                    if(a[i][j]%2==0)
                    {
                            ans+=a[i][j]/2;
                            hackgrid(a,i,j,EVEN);
                    }
                    else
                    {
                            ans+=((a[i][j]+1)/2)+1;
                            hackgrid(a,i,j,ODD);
                    }
                }
                //printf("%d\n",ans);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
