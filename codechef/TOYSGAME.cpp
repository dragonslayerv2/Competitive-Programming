#include<stdio.h>

int recurse(int n,int k,int turn)
{
    if(n==0) return turn*(-1);
    if(n==k) reutnr turn;
    if(n/k<=2||n==k*3-1) return     
    return recurse(n-k,k,turn*-1);
}
int main()
{
    int t,k;
    scanf("%d %d",&t,&k);
    while(t--)
    {
              int n;
              scanf("%d",&n);
              printf("%s\n",recurse(n,k,1)==1?"Brainy":"Clumsy");
              
    }
    return 0;
}
