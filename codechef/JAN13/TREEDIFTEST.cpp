#include <stdio.h>

#define MOD 1000000007

int main()
{
    int t;
    scanf("%d",&t);
    long long a,b,c;
    while(t--)
    {

        scanf("%lld %lld %lld",&a,&b,&c);

        if(a>c) a^=c^=a^=c;
        if(a>b) a^=b^=a^=b;
        if(b>c) b^=c^=b^=c;

        printf("%lld\n",((((a%MOD)*((b-1)%MOD))%MOD)*((c-2)%MOD))%MOD);
    }
    return 0;
}
