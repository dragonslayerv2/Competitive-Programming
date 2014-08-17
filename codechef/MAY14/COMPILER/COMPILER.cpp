#include<stdio.h>
#include<stack>
using namespace std;

char expression[2000000];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int longestPrefix=0;
		scanf("%s",expression);
		int leftCount=0;
		for(int i=0;expression[i];i++)
		{
			if(expression[i]=='<')
				leftCount++;
			else
				leftCount--;
			if(leftCount==0)
				longestPrefix=i+1;
			else if(leftCount<0)
				break;
		}
		
		printf("%d\n",longestPrefix);
	}
}
