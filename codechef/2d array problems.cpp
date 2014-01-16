#include<stdio.h>
#include<conio.h>

int  main()
{
      int a[10][10]={1};
      
      printf("%d\n",&a);
      printf("%d\n",a);
      printf("%d\n",*a);
      
      printf("%d",*(*a));
      getch();
}

