/*
  Name: interleaving shuffle string problem(Recursive Version)
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

int isShuffle(char *a,char *b,char *c)
{
    if(!(*a)&&!(*b)&&!(*c)) return 1;
    else if(*a==*c&&*b==*c)
    {
         return isShuffle(a+1,b,c+1)||isShuffle(a,b+1,c);
    }
    else if(*a==*c)
         return isShuffle(a+1,b,c+1);
    else if(*b==*c)
         return isShuffle(a,b+1,c+1);
    else
        return 0;
}

int main()
{
    printf("%d",isShuffle("chocolate","chips","cchocohilateps"));
    getchar();
    return 0;
}
