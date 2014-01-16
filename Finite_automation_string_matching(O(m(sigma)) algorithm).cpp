/*
	Name: Finite Automation String Matching
	Copyright: 
	Author: Shobhit Saxena
	Date: 25/01/13 20:38
	Description: THis algorithm find all occurences of pattern inside a string. 
				Preprocessing time: O(m(sigma)) refer to cormen question 32.4.8
				Since its an online algorithm no need to store text in an array. Read character by character.
				Matching TIme : O(n)
*/

#include<stdio.h>
#define PSize 1000
#define characters 26




void computeTransition(char *P,int table[PSize][characters])
{
//--------------First compute the prefix funtion through KMP preprocessing...----		
		char Pi[PSize]
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
//--------------------------------------------------------------------------------
		for(int i=0;i<characters;i++)
		{
			if('a'+i==P[0])
				table[0][i]=1;
			else
				table[0][i]=0;
		}

		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<characters;j++)
			{
				if(
			
			}
		}



}


int main()
{
	char pattern[PSize]="abaca";
	int table[PSize][characters];
	
	computeTransition(pattern,trans);
	
	int presentState=0;
	int found=0;
	
	while(1)
	{
		
			char c=getch();
		//	assert(c>='a'&&c<='z');
			system("cls");
			if(c=='\r') break;
			
			presentState=table[presentState][c-'a'];
			if(presentState==7) found++;
			
			printf("Character = %c\t Present State= %d\t Found= %d\n",c,presentState,found);
	}
	return 0;


}
