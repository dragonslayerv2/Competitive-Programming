#include<stdio.h>
#include<string.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char mat[200][200];
		memset(mat,0,sizeof(mat));
		int C;
		scanf("%d",&C);
		
		char str[300];
		scanf("%s",str);
		int k=0;
		int i=0;
		while(str[k])
		{
			for(int j=0;str[k]&&j<C;j++)
			{
				mat[i][j]=str[k++];				
			}
			i++;
			
			for(int j=C-1;str[k]&&j>=0;j--)
			{
				mat[i][j]=str[k++];				
			}
			i++;
		}
		for(int j=0;j<C;j++)
		{
			for(int i=0;mat[i][j];i++)
				printf("%c",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
