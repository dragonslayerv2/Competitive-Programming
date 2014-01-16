#include<stdio.h>
 
#define isSet(n) (flags&((long long)1<<(n)))
#define set(n) flags|=((long long)1<<(n))
 
int main()
{
    long long flags=0;
    int total;
    int t;
    int i;
    char a[101];
    char b[101];
    scanf("%d",&t);
    while(t--)
    {
              flags=0;
              total=0;
              
              scanf("%s %s",a,b);
              for(i=0;a[i]!='\0';i++)
                            set((a[i]-65));
              
              for(i=0;b[i]!='\0';i++)
              {
                                     if(isSet((b[i]-65)))
                                     total++;
              }
              printf("%d\n",total);
    }
    return 0;
}
