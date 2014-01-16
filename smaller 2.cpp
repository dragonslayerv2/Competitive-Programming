//This function will return power of 2 smaller or equal to n in O(log n) and O(1) time.
//Shobhit Saxena
#include<stdio.h>
#include<stdlib.h>
int smaller2(int n)
{
     int i=1;
     
     while(n)
     {
             n>>=1;
             i<<=1;       
     }
     i>>=1;
     return i;  
}

int Smaller2(int n)
{
     n=n>>1|n;
     n=n>>2|n;
     n=n>>4|n;
     n=n>>8|n;
     n=n>>16|n;
     n=(n+1)>>1;
     return n;  
}
int main()
{   printf("%d\n",smaller2(130));
    printf("%d\n",Smaller2(130));    
    system("pause");
}
//
