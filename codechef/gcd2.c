#include<stdio.h>

char b[251];

int reduce(int a)
{
    int i,res=0;
    for(i=0;b[i]!='\0';i++)
    {
        res=((res*10)+(b[i]-'0'))%a;
    }
    return(res);
}

int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
    int t,a,b1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        scanf("%s",b);
        if(0 == a){ printf(b);putchar('\n');}
        else
        {

                    b1=reduce(a);
                    printf("%d\n",gcd(b1,a));
        }

    }
    return 0;
}
