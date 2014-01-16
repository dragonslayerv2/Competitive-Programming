
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,l;
    char a[250];
    while(1)
    {
            scanf("%d",&n);
            if(n==0)
                    break;
           scanf("%s",str);
            l=strlen(a);
            l=l/n;
            
            for(i=0;i<n;i++)
            {
                  for(j=0;j<l;j++)
                  {
                          if(j%2==0)
                                    printf("%c",a[n*j+i]);
                         else
                                    printf("%c",a[(j+1)*n-(i+1)]);
                  }  
            }
            printf("\n");                    
    }
    return 0;
}
