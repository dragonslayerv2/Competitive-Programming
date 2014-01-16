#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


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
			//cout<<"At "<<T[i]<<" = "<<q<<endl;	
		}
		return false;
}

int main()
{
	char P1[1000]="ackoverflowst";
	char P2[1000]="stackoverflow";
	
	// do calcualte whether the string length of both the strings is same or not...
	
	char P3[1000];
	strcpy(P3,P2);
	strcat(P3,P2);
	
	int PI[1000];
	
	computePiFunction(P1,PI);
	
	printf("%d",matcher(P1,P3,PI));
}
