/*
	Name: Finite Automation Pattern Matching.
	Copyright:
	Author: Shobhit Saxena
	Date: 17/01/13 18:36
	Description: A online finite automation machine to test whether characters being entered contains a pattern "ab~ba~c".
				Refer to cormen for the description.
				Input must be only from set {'a','b','c'}
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<assert.h>
int main()
{
	int table[6][3]={
						{1,0,0},
						{1,2,0},
						{2,3,2},
						{4,3,2},
						{4,4,5},
						{1,0,0},
					};

	int presentState=0;
	int found=0;
	while(1)
	{
		
			char c=getch();
			assert(c>='a'&&c<='c');
			system("cls");
			if(c=='\r') break;
			
			presentState=table[presentState][c-'a'];
			if(presentState==5) found++;
			
			printf("Character = %c\t Present State= %d\t Found= %d\n",c,presentState,found);
	}

	return 0;
}

