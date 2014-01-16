#include<stdio.h>

void func(int m[100][100])
{
     printf("%d ",sizeof(m));
}

int main()
{
    int m[100][100];
    func(m);
    printf("%d",sizeof(m));
    getchar();
}
