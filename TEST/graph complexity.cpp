#include<stdio.h>
#include<math.h>

int main()
{
    for(int v=1;v<=10000;v++)
    {
            int max;
    for(int e=1;e<v*v;e++)
    {
            if(log(v)<=(((float)e+v)/(e+1.0)))
                                              max=e;
    }
    printf("%f\n",(float)(max*100)/v);
    }
    getchar();
}
