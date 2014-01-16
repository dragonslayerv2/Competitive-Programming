#include<stdio.h>
long long p(int n,int m)
{
    if(m==0) return 1;
    
    long long x=p(n,m/2);
    if(m%2==0) 
               return (x*x);
    else
               return (x*x*n);
}


void bruteforce(char *a,int l,char *chars,int n)
{
     long long total=p(n,l);
     long long i,j;
     int k=0;
     for(i=1;i<total;i++)
     {
                    j=i;
                    k=0;
                    while(j)
                    {
                            a[k++]=chars[j%n];
                            j=j/n;
                    }                 
                    a[k]=NULL;
                    printf("%s\n",a);
                    
     }
}
int main()
{
    char a[100];
    char chars[]="abcdefghijklmnopqrstuvwxyz";
    bruteforce(a,10,chars,sizeof(chars));
    printf("%lld",p(2,2));
    getchar();
    return 0;
}
