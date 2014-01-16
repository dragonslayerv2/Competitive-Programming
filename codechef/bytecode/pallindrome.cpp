#include<stdio.h>

void pallindrome(int n,int k)
{

    int *p=new int[n];
    for(int i=1;i<n-1;i++)
    {
            p[i]=0;
    }
    p[0]=p[n-1]=1;
    if(n%2==1)
    {
              p[n/2]+=k%10;
              k=k/10;
    }

              for(int i=n/2-1;i>=0;i--)
              {
                      p[i]=p[n-i-1]+=k%10;
                      k=k/10;
              }

    for(int i=0;i<n;i++)
    {
     printf("%d",p[i]);
    }
    printf("\n");
    delete p;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int n,k;
              scanf("%d %d",&n,&k);
              pallindrome(n,k-1);
    }
    return 0;
}
