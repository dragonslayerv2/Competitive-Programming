#include<stdio.h>

#define lowercase(x) (x&0x20)
#define uppercase(x) (!(x&0x20))
#define tolower(x) (x|0x20)
#define toupper(x) (x&~(0x20))
#define changecase(x) (x^0x20)



int main()
{
    printf("%c",toupper('a'));
   // printf("%d",uppercase('A'));
    getchar();
    return 0;
}

