// Print Spiral... in a 2d array of size MAX*MAX

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 12
int main()
{  
    int a[MAX][MAX];
    int x,y;
    if(MAX%2!=0)
                x=y=MAX/2;
    else
    {
                x=MAX/2;
                y=x-1;
    }
    int k=0;
    int moves1=1;
    int moves=moves1;
    int dir=0;
    for(int i=0;i<MAX;i++)
    {
            for(int j=0;j<MAX;j++)
            {
                    a[i][j]=-1;
            }
    }
    while(k<MAX*MAX&&!kbhit())
    {
              a[x][y]=k++;
              if(moves==0)
              {
                          dir=(dir+1)%4;
                          if(dir%2==0)
                                    moves=moves1=moves1+1;
                          else
                                    moves=moves1;
              }
              switch(dir)
              {
                         case 0:y++;break;
                         case 1:x--;break;
                         case 2:y--;break;
                         case 3:x++;break;
              }
              system("cls");     
              moves--;
              for(int i=0;i<MAX;i++)
              {
                      for(int j=0;j<MAX;j++)
                              {
                                            if(a[i][j]==-1) printf("     "); 
                                            else printf("%3d  ",a[i][j]);
                              }
                      printf("\n");
              }
              for(int i=0;i<30000000;i++);
    }
    getch();
    return 0;
}
