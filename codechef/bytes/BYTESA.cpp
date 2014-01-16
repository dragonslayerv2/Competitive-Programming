#include<stdio.h>
#include<string.h>
char map[10]={'0','1','n','n','n','n','9','n','8','6'};


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char input[100];
		char output[100];
		bool flag=true;
		scanf("%s",input);
		int k=0;
		for(int i=strlen(input)-1;i>=0;i--)
		{
			if(map[input[i]-'0']=='n')
			{
				flag=false;
				break;
			}
			else
			{
				output[k++]=map[input[i]-'0'];
			}
		}
		if(flag)
		{
			output[k]=NULL;
			printf("YES\n%s\n",output);
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
