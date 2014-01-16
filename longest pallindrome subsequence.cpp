/*
  Name: Longest Pallindrome Subsequence
  Copyright: 
  Author: Shobhit Saxena
  Date: 14/12/12 17:13
  Description: Algorithm to find the longest pallindrome that is the subsequence of the given string.
  O(n^2) algorithm.
*/

#include<stdio.h>
#include<string.h>
#define MAX 100

#define max(a,b) a>b?a:b


int lps(char *string,int l,int LPS[MAX][MAX])
{
  
     for(int i=0;i<l;i++)
             LPS[i][i]=1;
     for(int L=1;L<l;L++)
     {
             for(int i=0;i<l-L;i++)
             {
                     int j=i+L;
                     if(string[i]==string[j])
                                             LPS[i][j]=2+LPS[i+1][j-1];
                     else
                                             LPS[i][j]=max(LPS[i+1][j],LPS[i][j-1]);
             }
     } 
     return LPS[0][l-1];
}

char * printLPS(char *p, char *string,int l,int LPS[MAX][MAX])
{
     int i=0;
     int j=l-1;
     
     int start=0;
     int end=LPS[0][l-1]-1;
     p[end+1]=NULL;
     while(end>=start)
     {
                      if(string[i]==string[j])
                      {
                                            //  printf("at %d %d <=%c",start,end,string[i]);
                                              p[start++]=p[end--]=string[i];
                                              i=i+1;
                                              j=j-1;                                                    
                      }
                      else
                      {
                                              if(LPS[i][j-1]>LPS[i+1][j])
                                                                         j=j-1;
                                              else
                                                                         i=i+1;
                      }
     }
     return p;
}


int main()
{
    char string[]="aibohphobia";
    int l=sizeof(string)-1;
    int LPS[MAX][MAX];
    char p[MAX];
    
    memset(LPS,0,sizeof(LPS));
    
    printf("Length=%d\n",lps(string,l,LPS));
    printf("String=%s",printLPS(p,string,l,LPS));
    getchar();
}
