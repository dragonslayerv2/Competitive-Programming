/*
  Name: Dyck's word
  Copyright:
  Author: Shobhit Saxena
  Date: 09/12/12 11:13
  Description:
    nth Catalan number is the number of Dyck words of length 2n. A Dyck word is a string consisting of n X's and n Y's such that no initial segment of the string has more Y's than X's (see also Dyck language). For example, the following are the Dyck words of length 6:
                                      XXXYYY     XYXXYY     XYXYXY     XXYYXY     XXYXYY.
*/

#include<stdio.h>

#define MAX 100
#define X 'X'
#define Y 'Y'

void dycksword(int l,int x=0,int y=0,int i=0,char *word=NULL)  // x represents total number of x left for use, y represent y left for use, word is an char array where words are temporarily stored. word is allocated its memory during first call to the function i is the current position where the character is to be filled.
{
     if(l==0){printf("Error: l must be greater than 0.\n");return;}
     if(l%2) {printf("Error: l must be an even number.\n");return;}

     if(i==0)
     {
             char wrd[MAX];
             wrd[i]=X;
             dycksword(l,l/2-1,y+1,i+1,wrd);
     }
     else if(i==l) // this means we are at the end. terminate the string and print it.
     {
          word[i]=NULL;
          printf("%s\n",word);
     }
     else if(!y&&x)// tht character can only be x. make it x and increase the number of y.
     {
          word[i]=X;
          dycksword(l,x-1,y+1,i+1,word);
     }
     else if(!x&&y) // all the characters later to this position are now y.
     {
          word[i]=Y;
          dycksword(l,x,y-1,i+1,word);
     }
     else if(x&&y)// character can either be x or y. if x decrease x left and increase y. if y simply decrease y.
     {
          word[i]=X;
          dycksword(l,x-1,y+1,i+1,word);

          word[i]=Y;
          dycksword(l,x,y-1,i+1,word);
     }
}
int main()
{
    dycksword(8);
    getchar();
    return 0;
}
