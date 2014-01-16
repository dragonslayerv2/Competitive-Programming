#include<stdio.h>
#include<conio.h>
int main()
{
    int n;
    float f;
    scanf("%d %f",&n,&f);
    if((n)%5!=0||f<(float)n+0.50)
                        printf("%.2f",f);
    else
                        printf("%.2f",f-n-0.50);
    getch();
    return 0;
}
