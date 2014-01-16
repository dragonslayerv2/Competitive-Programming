// Triple dycks word//.....
#include<stdio.h>

#define MAX 109
#define MOD 1000000007
int w[MAX];

void precompute()
{
        w[0]=1;
        w[1]=1;
        for(int n=2;n<MAX;n++)
        {
            w[n]=0;
            for(int i=0;i<=n-1;i++)
            {
                for(int j=0;j<=n-1-i;j++)
                {
                   w[n]=(w[n]+w[i]*w[j]*w[n-1-(i+j)])%MOD;
                }
            }
        }
}
int main()
{
    precompute();
    for(int i=0;i<100;i++)
    {
            printf("%d ",w[i]);
    }
}
