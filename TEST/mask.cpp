#include<stdio.h>


#define MASK 0x80000000


int bintogray(int n)
{
    int ans=0,bit;
    ans=bit=(n&MASK?1:0);
    printf("%d",bit);
    n<<=1;
    while(n)
    {
            ans<<1;
            int bit=(n&MASK)?1:0;
            ans|=bit;
            n<<=1;
    }
    return ans;
}



int main()
{
    bintogray(21);
}
