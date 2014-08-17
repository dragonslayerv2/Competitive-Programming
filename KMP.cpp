#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define PATTERN_SIZE 100
#define TEXT_SIZE 10000

void computePiFunction(char *p,int *Pi)
{
		int m=strlen(p);

		Pi[0]=-1;
		int k=-1;
		
		for(int i=1;i<m;i++)
		{
		
			while(k>=0&&p[k+1]!=p[i])
				{k=Pi[k];}
			if(p[k+1]==p[i])
				k++;
			Pi[i]=k;	
		}
}

void matcher(char *P,char *T,int *Pi)
{
	int m=strlen(P);
	int q=-1;
	for(int i=0;T[i];i++)
	{
		while(q>=0&&P[q+1]!=T[i])
			q=Pi[q];
		if(P[q+1]==T[i])	
			q++;
		if(q==m-1)
		{
			printf("Found at pos=%d\n",i-m+1);
			q=Pi[q];
		}
	}
}

int main()
{
	
	
	char pattern[PATTERN_SIZE],text[TEXT_SIZE];
	int Pi[PATTERN_SIZE];
	
	gets(pattern);
	computePiFunction(pattern,Pi);

	gets(text);
	matcher(pattern,text,Pi);
	
	getchar();
	return 0;
}
