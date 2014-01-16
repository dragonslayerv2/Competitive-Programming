#include<stdio.h>
int recurse(int n,int turn)
{
    if(n==1)
            return turn;
    
    for(int i=n-1;i>=1;i--)
    {
            if(n%i==0)
            {
                      if(recurse(n-i,turn*(-1))!=turn) 
                                                       return turn *(-1);
            }
    }
    return turn;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int n;
              scanf("%d",&n);
              printf("%s\n",(recurse(n,1)==(-1))?"ALICE":"BOB");
    }
    return 0;
}
