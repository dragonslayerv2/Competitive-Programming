#include<stdio.h>
#define MAX 1000010
char input[MAX];
		char twin1[MAX];
		char twin2[MAX];
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		
		int p1=0;
		int p2=0;
		twin1[p1]=0;
		gets(input);
		for(int i=0;input[i];i++)
		{
			if(input[i]==twin1[p2])
				twin2[p2++]=input[i];
			else
				twin1[p1++]=input[i];
				
		}
		twin1[p1]=NULL;
		if(p1==p2&&p1>=1)
			printf("%s\n",twin1);
		else
			printf("Twins don\'t exist\n");
	}
	return 0;
}
