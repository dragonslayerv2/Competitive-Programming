#include<stdio.h>
#include<string.h>

#define swap(a,b) (a^=b^=a^=b)

void reverse(char a[],int h,int l=0)
{
     if(l<h)
     {
            swap(a[l],a[h]);
            reverse(a,h-1,l+1);
     }
}

int main()
{
    char a[]="SHOBHIT";
    reverse(a,strlen(a)-1);
    printf(a);
    getchar();
    return 0;
}
