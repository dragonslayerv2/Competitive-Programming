#include<stdio.h>
#include<conio.h>
int main()
{
     
     for(int n=0;n<100;n++)
     {
     int i=1;
     int m=n;
     while(m)
     {
             m>>=1;
             i<<=1;       
     }
     i>>=1;
     printf("%d=%d\n",n,i);
     getch();
     }  
}
