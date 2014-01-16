#include<stdio.h>
#include<string.h>

int main()
{
	int t;
	scanf("%d",&t);
	char N[150001];
	getchar();
	while(t--)
	{
		gets(N);
		int l=strlen(N);
		int flippoint=-1;
		int i;
		for(i=l-2;i>=0;i--)
		{
			if(N[i]<N[i+1])
			{ 
				flippoint=i;
				break;
			}
		}
		
		int hashmap[10]={0,0,0,0,0,0,0,0,0,0};	
		//cout<<"flippoint="<<flippoint<<endl;;	
		char flipnumber=N[flippoint];
		if(flippoint!=-1)
		{
			for(;i<l;i++)
			{
				hashmap[N[i]-'0']++;
			}
			for(i=0;i<10;i++)
			{
				if(hashmap[i]&&i+'0'>flipnumber)
				{N[flippoint]='0'+i;hashmap[i]--;break;}
			}
			int numindex=0;
			for(i=flippoint+1;i<l;i++)
			{
				while(!hashmap[numindex]) numindex++;
				N[i]=numindex+'0';
				hashmap[numindex]--;
			}
			printf("%s\n",N);
		}
		
		else
			printf("-1\n");
	}
	return 0;
}
