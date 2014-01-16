//Bucket problem 
/*
  Name: Shobhit Saxena
  Copyright: 
  Author: 
  Date: 25/10/12 11:32
  Description: bucket Problem Solution
*/



#include<stdio.h>
#include<string.h>
#define MAX 10
void recurse(float glasses[MAX][MAX],int x,int y,float c)
{
     if(glasses[x][y]<c)
                        return;
     else
     {
         float extra=glasses[x][y]-c;
         glasses[x][y]=c;
         glasses[x+1][y]+=extra/2;
         glasses[x][y+1]+=extra/2;
         recurse(glasses,x+1,y,c);
         recurse(glasses,x,y+1,c);  
     }
}

int main()
{
    float glasses[MAX][MAX];
    memset(glasses,0,sizeof(glasses));
    scanf("%f",&glasses[0][0]);
    float c;//Capacity
    scanf("%f",&c);
    recurse(glasses,0,0,c);
    for(int i=0;i<MAX;i++)
    {
            for(int j=0;j<MAX;j++)
            {
                    printf("%.2f ",glasses[i][j]);
            }
            printf("\n");
    }
    fflush(stdin);
    getchar();
}
