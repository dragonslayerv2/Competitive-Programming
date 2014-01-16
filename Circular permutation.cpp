/*
	Name: To check whether a string is circular permutation of another string.
	Copyright: 
	Author: 
	Date: 25/01/13 16:11
	Description: This program finds whether a string is a circular permutation of another string. 2 good ways exist for this thing. this can be computer through 
				1. Find the largest prefix of second string that is the suffix of some prefix of srting 2. That gives u the place of rotation.
				2. Concatenate the two strings and then find the second string in the first one. Then the second string is the circular permutation of first string.				
*/


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
int isCircular(char *P,char *T)
{
		int Pi[PATTERN_SIZE];
		computePiFunction(P,Pi);
		int m=strlen(P);
		int n=strlen(T);
		if(n!=m) return 0;
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
				q=Pi[q];
			}	
		}// to print the place of rotation print q.....
		q++;
		for(int i=0;q<m;q++,i++)
		{
			if(P[q]!=T[i])
				return 0;
		}
		return 1;
}

int main()
{
	printf("%d",isCircular("ackoverflowst","stackoverflow"));
	getchar();
	return 0;
}
