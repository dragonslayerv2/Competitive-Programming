#include<stdio.h>


int subsetsum(int a[],int n)
{
    int pow=1;
    int sum=0;
    for(int i=0;i<n;i++)
            pow=pow<<1;
    for(int i=1;i<pow;i++)
    {
            int j=i;
            int k=0;
            while(j)
            {
                    if(j&1) sum+=a[k];
                    j>>=1;
                    k++;
            }
    } 
    return sum;
}
int main()
{
    int a[]={1,2,3};
    printf("sum = %d",subsetsum(a,sizeof(a)/sizeof(*a)));
    getchar();
}
