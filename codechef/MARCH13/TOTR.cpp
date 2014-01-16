#include<stdio.h>
#include<ctype.h>
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#define islower(x) ((x)&0x20)
#define isupper(x) (!((x)&0x20))

int main()
{
	int t;
	int hash[100];
	int i;
	
	scanf("%d ",&t);
	
	
	for(i=0;i<26;i++)
	{
		hash[i]=GETCHAR()-'a';
	}
	
	while(t--)
	{
		char string[101];
		scanf("%s",string);
		for(i=0;string[i];i++)
		{
			if(string[i]=='_')
				PUTCHAR(' ');
			else if(isalpha(string[i]))
			{
				if(isupper(string[i]))
					PUTCHAR('A'+hash[string[i]-'A']);	
				else
					PUTCHAR('a'+hash[string[i]-'a']);	
			}
			else
				PUTCHAR(string[i]);
		}
		PUTCHAR('\n');
	}
	return 0;
}
