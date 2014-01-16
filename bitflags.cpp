#include<stdio.h>
#include<string.h>
#define MAX 100000

int flags[MAX/32+2];

#define isSet(n) flags[n>>5]&(1<<(n&31))
#define unset(n) flags[n>>5] &= ~(1<<(n&31))
#define set(n) flags[n>>5]|=(1<<(n&31))

