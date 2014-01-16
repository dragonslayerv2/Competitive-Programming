#include<stdio.h>
#define MAX 1000
int flags[MAX];

#define isSet(n) flags[n>>5]&(1<<(n&31))
#define unset(n) flags[n>>5] &= ~(1<<(n&31))
#define set(n) flags[n>>5]|=(1<<(n&31))

int main()
{
    
}
