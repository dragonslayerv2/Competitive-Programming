#include<stdio.h>


int recurse(unsigned long n)
{
    if(n==0) return 0;
    else
    {
        
        unsigned long x=recurse(n/2)+recurse(n/3)+recurse(n/4);
        return x>n?x:n; 
    }
}
int main()
{    
    unsigned long n;
    while(scanf("%lu",&n)>0)
    {
                            printf("%lu\n",recurse(n));
    }
    return 0;
}
