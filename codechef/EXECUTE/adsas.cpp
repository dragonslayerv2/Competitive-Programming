#include<stdio.h>
#include<string.h>
int main()
{
	int c,i,j,k,t;
	char a[500],b[500],len,test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&c);
		scanf("%s",a);
		j=0;i=0;k=0;t=0;
		len=strlen(a);
		while(j<c)
		{
			i=t++;
			b[k++]=a[i];
			while(i<len)
			{
				i=i+(c-j-1)*2+1;
				if(i>=len)
					break;
				else
				{
					b[k++]=a[i];
				}
				if(i>len)
					break;
				else
				{
					i=i+(j*2)+1;
					b[k++]=a[i];
				}
			}
			j++;
		}
		b[k]='\0';
		for(i=0;i<len;i++)
			printf("%c",b[i]);
		printf("\n");
	}
	return 0;
}
