#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<limits.h>
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main()
{
    int a[50];
    srand(time(NULL));
    printf("--Before sorting--\n\n");
    for(int i=0;i<50;i++)
    {       
             a[i]=rand()%100;
             printf("%d\t",a[i]);
    }
    qsort (a, 50, sizeof(int), compare);
    
    printf("\n\n--After Sorting--\n\n");
    
    for(int i=0;i<50;i++)
    {       
             
             printf("%d\t",a[i]);
    }
    getch();
}
