#include<stdio.h>
#include<stdlib.h>
int main()
{
int t,n,x,*a,i,j,s,r,c;
scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%d%d",&n,&x);
a=(int *)malloc(n*sizeof(int));
s=0;
for(j=0;j<n;j++)
{
scanf("%d",a+j);
s=s+a[j];
}
r=s%x;
s=s/x;
if(r!=0)
{for(j=0;j<n;j++)
{
if(a[j]<r)
{
c=-1;
printf("%d\n",c);
break;
}
else if(j==n-1)
printf("%d\n",s);
}
}
else printf("%d\n",s);
}
fflush(stdin);
getchar();
return 0;
}
