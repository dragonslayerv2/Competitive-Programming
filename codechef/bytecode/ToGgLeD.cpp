#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    int n,k,i;
    while(t--)
    {
              scanf("%d %d",&n,&k);
              for(i=0;i<n;i++)
              {       
                      if(!(k&1)) {break;}
                      k=k>>1;
              }  
              if(n==i)          printf("ON\n");
              else                 printf("OFF\n");
    }
    return 0;
}
