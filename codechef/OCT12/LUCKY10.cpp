#include<stdio.h>
#define limits 200010

#define wh(a,b,c) while(a>0&&b>0)\
                  {\
                    a--;\
                    b--;\
                    putchar_unlocked(c);\
                  }
int main()
{
    int t,i;
    scanf("%d",&t);
    char a[limits],b[limits];
    while(t--)
    {
              fflush(stdin);
              scanf("%s",a);
              fflush(stdin);
              scanf("%s",b);
              int as4=0,ae4=0,ae7=0,as7=0;
              int bs4=0,be4=0,be7=0,bs7=0;
              for(i=0;a[i]!='\0';i++)
              {
                                     if(a[i]<'4') as4++;
                                     else if(a[i]=='4') ae4++;
                                     else if(a[i]<'7') as7++;
                                     else if(a[i]=='7') ae7++;           
                                     
                                     if(b[i]<'4') bs4++;
                                     else if(b[i]=='4') be4++;
                                     else if(b[i]<'7') bs7++;
                                     else if(b[i]=='7') be7++;
              }

              wh(ae7,bs7,'7')
              wh(be7,as7,'7')
              wh(ae7,bs4,'7')
              wh(be7,as4,'7')
              
              wh(be7,ae4,'7')
              wh(ae7,be4,'7')
              
              wh(ae7,be7,'7')
                                       
              wh(ae4,bs4,'4')         
              wh(be4,as4,'4')
              wh(ae4,be4,'4')
              
              putchar_unlocked('\n');
    }
    return 0;
}
