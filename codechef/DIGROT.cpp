#include<stdio.h>

inline int shiftleft(int n)
{
    int pow=1;
              while(n/(pow*10)!=0)
                  pow*=10;
    return ((n%pow)*10+n/pow);
}

inline int shiftright(int n)
{
    
    int pow=1;
              while(n/(pow*10)!=0)
                  pow*=10;
    return ((n/10)+(n%10)*pow);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int n;
              scanf("%d",&n);
              
              int max;

              int sl,sr,slsr,srsl;
              sl=sr=n;
              
              
              slsr=shiftleft(shiftright(n));
              srsl=shiftright(shiftleft(sl));
              max=srsl>slsr?srsl:slsr;
              while(n)
              {
                        
                        sl=shiftleft(sl); 
                        sr=shiftright(sr); 
                  //    printf("sl=%d\tsr=%d\n",sl,sr);
                        
                        
                        if(sl>max) max=sl;
                        if(sr>max) max=sr;
                        
                        n/=10;
              }
              
              printf("%d\n",max);
    }
    return 0;
}
