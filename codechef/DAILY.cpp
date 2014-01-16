#include<stdio.h>

inline int nCr(int n,int r)
{
    int nm=1;
    int rm=1;
    while(r)
    {
              nm=nm*(n--);
              rm*=(r--);
    }
    return nm/rm;
}



int main()
{
    int seats;
    int x,m,i;
    char string[100];
    int ans=0;
    scanf("%d %d",&x,&m);
    while(m--)
    {
            
              
              scanf("%s",string);
              
              for(i=0;i<9;i++)
              {
                              seats=6+6*'0'-string[4*i]-string[4*i+1]-string[4*i+2]-string[4*i+3]-string[53-2*i]-string[53-2*i-1];
                              if(seats>=x)
                              ans+=nCr(seats,x);
              }
    }
    printf("%d\n",ans);
    return 0;
}
