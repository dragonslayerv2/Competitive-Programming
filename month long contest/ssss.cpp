#include<stdio.h>

void recurse(char *a,char *b,char *c,int i=0)
{
                 if((*a==NULL&&*b==NULL))
                 {
                                        c[i]=NULL;
                                        printf("%s\n",c);
                                        return;
                 }
                 else
                 {
                     if(*a==NULL)
                     {
                                 c[i]=*b;
                                 recurse(a,b+1,c,i+1);
                     }
                     else if(*b==NULL)
                     {
                                 c[i]=*a;
                                 recurse(a+1,b,c,i+1);
                     }
                     else
                     {
                                 c[i]=*b;
                                 recurse(a,b+1,c,i+1);

                                 c[i]=*a;
                                 recurse(a+1,b,c,i+1);
                     }
                 }
}
int main()
{
    char c[100];
    char a[]="abe";
    char b[]="cde";
    recurse(a,b,c);
    getchar();
}
