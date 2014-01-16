/*
  Name: Wythoff's game
  Copyright:
  Author:
  Date: 06/11/12 21:10
  Description:
*/
#include<stdio.h>


/*

                      2 1
                      2 1


*/
int brute(int a, int b,int turn)
{
    if(a==0&&b==0)   return turn*-1;     // last member wins
    if(a==b&&(a==0||b==0)) return turn; // if same number of elements current member wins

    //-----brute starts--------------------
    for(int i=1;i<=a;i++)
    {
            if(brute(a-i,b,turn*(-1))==turn) return turn;
    }
    for(int i=1;i<=b;i++)
    {
            if(brute(a,b-i,turn*(-1))==turn) return turn;
    }
    for(int i=1;i<=(a<b?a:b);i++)
    {
            if(brute(a-i,b-i,turn*(-1))==turn) return turn;
    }
    return turn*(-1); // if no way to win, second person wins....
}




int main()
{
    int a,b;
  //  scanf("%d %d",&a,&b);
    printf("%c\t\n",brute(4,3,1)==1?'W':'L');
    for(int i=0;i<=10;i++)
    {
            for(int j=0;j<10;j++)
            {
                    printf("%c\t",brute(i,j,1)==1?'W':'L');
            }

    printf("\n");
    }

    fflush(stdin);
    getchar();
}
