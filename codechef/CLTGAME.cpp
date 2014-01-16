/*http://www.codechef.com/AMRITA11/problems/CLTGAME
 	

    My Submissions
    All Submissions

All submissions for this problem are available.

Alice and Bob are playing a game of moving coin on a N x N grid of 0s and 1s. Rows are numbered 1 to N from top to bottom and Columns are numbered 1 to N from left to right. Starting from a cell in the 1st row, they take turns alternately each time moving the coin to the next row. From a cell (i,j) they can move the coin to any of the cells (i+1,j-1), (i+1,j), (i+1,j+1) as long as it lies inside the grid. The game halts when the coin reaches the last row. Alice wants to collect as many 1s as possible along the path, while Bob wants to collect as many 0s as possible.

The game starts with Alice placing the coin in a cell in the 1st row, then Bob moving it from the 1st row to the 2nd row and then Alice moving it to the 3rd row and so on. In how many cells in the 1st row can Alice place the coin initially, such that the number of 1s encountered along the path from top to bottom is at least K, if both play optimally. Note that such a path covers exactly N cells, including a cell in the 1st Row.
Input

The first line contains the number of test cases T. T cases follow. Each test case consists of N K in the first line followed by the description of the grid in the next N lines. Each row of the grid is given as a string of 0s and 1s, without spaces in between. A blank line precedes each test case.
Output

Output T lines, one for each case containing the required answer.

Constraints

1 <= T <= 10
3 <= N <= 1000
1 <= K <= N

Example

Input:
2

3 2
010
100
101

4 2
1100
0000
0010
1101

Output:
1
2

-----------*/
#include<stdio.h>
#define MAX 1000
struct coins
{
       int zero;
       int one;
};

coins memory[MAX][MAX];
int flag[MAX][MAX];

coins recurse(char x[MAX][MAX],int i,int j,int n)
{
    
    if(flag[i][j]==1)              return memory[i][j];
    if(i==n-1)
    {
              coins a;
              a.zero=0;
              a.one=0;
              if(x[i][j]=='1') a.one++;
              else             a.zero++;
              
              memory[i][j]=a;
              flag[i][j]=1;
              return a;
    
    }
    else
    {
              coins a,b,c;
              a.one=a.zero=b.one=b.zero=c.one=c.zero=-1;
              coins d;
              a=recurse(x,i+1,j,n);
              if(j!=n-1)           c=recurse(x,i+1,j+1,n);
              if(j!=0)             b=recurse(x,i+1,j-1,n);
              if(i%2!=0)
              {
                        d= a.zero>b.zero?(a.zero>c.zero?a:c):(b.zero>c.zero?b:c);
              }
              else
              {
                        d= a.one>b.one?(a.one>c.one?a:c):(b.one>c.one?b:c);
              }  
              
              if(x[i][j]=='1') d.one++;
              else             d.zero++;
    
              memory[i][j]=d;
              flag[i][j]=1;
              return d;
    }
}

int main()
{
    char a[MAX][MAX];
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
              int r,k,count=0;
              scanf("%d %d",&r,&k);
              for(int i=0;i<r;i++)
              {
                      scanf("%s",a[i]);
                      for(int j=0;j<r;j++)
                              flag[i][j]=0;
              }
              for(int i=0;i<r;i++)
              {
                      coins k2=recurse(a,0,i,r);
                      if(k2.zero==k) count++;
                      /*printf("%d=",i);
                      printf("%d\n",k2.zero);*/
              }
              printf("%d\n",count); 
    }
    return 0;
}
