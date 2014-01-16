#include<stdio.h>

int hi()
{
    printf("hi..");
    return 1;
}

int bye()
{
    printf("byeee...");
    return 1;
}
int x()
{
    printf("x...");
    return 1;
}

int main()
{
    if(bye()||hi()||!x())
                   printf("hola");
                   getchar();

}
