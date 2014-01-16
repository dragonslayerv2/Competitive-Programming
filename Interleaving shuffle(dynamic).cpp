/*
  Name: interleaving shuffle string problem(Dynamic Programming Version)
  Copyright: 
  Author: Shobhit Saxena
  Date: 15/11/12 20:16
  Description: 
               Suppose you are given three strings of characters: X, Y , and
               Z, where |X| = n, |Y| = m, and |Z| = n + m. Z is said to
               be a shuffle of X and Y iff Z can be formed by interleaving
               the characters from X and Y in a way that maintains the leftto-
               right ordering of the characters from each string.
*/
#include<stdio.h>
#include<string.h>
#define MAX 100

int isShuffle(char *a,char *b,char *c)
{
    int l1=strlen(a);
    int l2=strlen(b);
    int l3=strlen(c);
    if(l1+l2!=l3) return 0; // prelim test....
    
    int array[MAX][MAX],i,j;
    array[0][0]=1;
    
    for(i=1;i<=l1;i++)
            if(a[i-1]==c[i-1]) array[0][i]=array[0][i-1];
    for(i=1;i<=l2;i++)
            if(b[i-1]==c[i-1]) array[i][0]=array[i-1][0];
    for(i=1;i<=l2;i++)
    {
            for(j=1;j<=l1;j++)
            {
                              if(b[i-1]==c[i+j-1]&&a[j-1]==c[j+i-1])
                                         array[i][j]=array[i-1][j]||array[i][j-1];
                              else if(a[j-1]==c[j+i-1])
                                         array[i][j]=array[i][j-1];
                              else if(b[i-1]==c[j+i-1])
                                         array[i][j]=array[i-1][j];
                              else array[i][j]=0;
            }
    }
    return array[l2][l1];
}

int main()
{
    printf("%s",isShuffle("chocolate","chips","cchocohilateps")?"TRUE":"FALSE");
    getchar();
    return 0;
}
