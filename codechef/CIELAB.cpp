#include<stdio.h>

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int dif=a-b;
    printf("%d",(dif/10)*10+(dif%10==2?1:2));
    return 0;
}
