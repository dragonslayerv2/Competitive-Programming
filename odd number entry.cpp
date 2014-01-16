// O(n) solution to test for odd number entry in an array
#include<stdio.h>
#include<conio.h>
#define br -1

int main()
{
        int x=0;
        int n;
        while(1)
        {
                scanf("%d",&n);
                if(n==br)
                         break;
                x^=n;
        }
        printf("%d",x);
        getch();
        return 0;
}
