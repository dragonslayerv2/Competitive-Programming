#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	char string[210];
	
	while(t--)
	{
		char hashmap[255];
		memset(hashmap,0,sizeof(hashmap));
		
		scanf("%s",string);
		int count=0;
		int i;
		for(i=0;string[i];i++)
		{
			if(hashmap[string[i]]==0)
			{
				count++;
				hashmap[string[i]]=1;
			}
			else
				hashmap[string[i]]=0;
		}
		printf("%d\n",count);
	}
	return 0;
}
