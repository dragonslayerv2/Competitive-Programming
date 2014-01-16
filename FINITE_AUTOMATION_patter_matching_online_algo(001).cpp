/*
	Name: Finite Automation Pattern Matching.
	Copyright:
	Author: Shobhit Saxena
	Date: 17/01/13 18:36
	Description: A online finite automation machine to test whether characters being entered contains a pattern "0001".
				Refer to cormen for the description.
				Input must be only from set {'0','1'}
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<assert.h>
int main()
{
	int table[5][2]={
						{1,0},
						{2,0},
						{3,0},
						{3,4},
						{1,0},
					};

	int presentState=0;
	int found=0;
	while(1)
	{

			char c=getch();
            if(c=='\r') break;
			system("cls");

			assert(c=='0'||c=='1');
			presentState=table[presentState][c-'0'];
			if(presentState==4) found++;

			printf("Character = %c\t Present State= %d\t Found= %d\n",c,presentState,found);
	}

	return 0;
}

