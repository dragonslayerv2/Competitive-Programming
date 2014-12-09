#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


// KMP 
void computePiFunction(char *p,int *Pi)
{
	int m=strlen(p);
	Pi[0]=-1;
	int k=-1;
	
	for(int i=1;i<m;i++)
	{
		while(k>=0&&p[k+1]!=p[i]) {k=Pi[k];}
		if(p[k+1]==p[i])
			k++;
		Pi[i]=k;	
	}
}

int matcher(char *P,char *T,int *Pi)
{
	int m=strlen(P);
	int q=-1;
	for(int i=0;T[i];i++)
	{
		while(q>=0&&P[q+1]!=T[i])
		{
			q=Pi[q];
		}
		if(P[q+1]==T[i])	q++;
		if(q==m-1)
		{
			return true;
			q=Pi[q];
		}
	}
	return false;
}

int main()
{
	char P1[4000];

	char P2[4000];
	cin>>P1>>P2;
	int len=strlen(P1);
	char P3[5000];
	strcpy(P3,P2);
	strcat(P3,P2);
	
	int PI[5000];
	
	computePiFunction(P1,PI);
	int solution = matcher(P1,P3,PI);
	solution = min(solution,len-solution);
	printf("%d",solution);
}


char P1[4000];

	char P2[4000];
	cin>>P1>>P2;
	int len=strlen(P1);
	char P3[5000];
	strcpy(P3,P2);
	strcat(P3,P2);
	
	int PI[5000];
	
	computePiFunction(P1,PI);
	int solution = matcher(P1,P3,PI);
	solution = min(solution,len-solution);
	printf("%d",solution);
