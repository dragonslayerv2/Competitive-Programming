#include<stdio.h>
#include<math.h>

int main()
{
    float a;
    for(int n=1;n<10;n++)
    {
            a=0.0;
     for(int r=1;r<=n;r++)
     {
             a+=pow((pow(2,r)+pow(0.5,r)),r);
     }
     printf("%f\n",a);
    }
    getchar();
}
