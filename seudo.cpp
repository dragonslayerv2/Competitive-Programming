#include<stdlib.h>
#include<time.h>
#include<stdio.h>

int main()
{
	srand(time(NULL));
	for(int i=0;i<11;i++)
	{
		printf("%d",rand()%2);
	
	}


}
