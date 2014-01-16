#include<stdio.h>
int main()
{
    FILE *p;
    p=fopen("aa.txt","w");
    for(int i=1;i<=5000000;i++)
    {
            fprintf(p,"%d, ",i);
    }
    fclose(p);
    
}
