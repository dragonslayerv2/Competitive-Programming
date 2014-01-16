#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[100000];
	for(int i=0;i<n;i++)
		a[i]=i+1;
	int pos=0;
	while(n>1)
	{
		pos=(pos+(m-1))%n;
		for(int i=pos;i<n-1;i++)
		{
			a[i]=a[i+1];
		}

		
		n--;
	}
	printf("%d",a[0]);
	return 0;
}
