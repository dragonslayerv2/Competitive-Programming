#include<stdio.h>

#define islower(x) (x&0x20)
#define isupper(x) (!(x&0x20))
#define tolower(x) (x|0x20)
#define toupper(x) (x&~(0x20))
#define switchcase(x) (x^0x20)

int main()
{
   printf("%c",switchcase('a'));
   getchar();
}
