/*
  Name: Levenshtein Distance(Dynamic Program)
  Copyright: 
  Author: Shobhit Saxena 
  Date: 15/11/12 17:21
  Description: O(n^2) algorithm for finding edit distance.               
*/
#include<stdio.h>
#include<string.h>

#define MAX 100

#define min(a,b,c) (a<b?a<c?a:c:b<c?b:c)



int dis(char *a,char *b,int l1,int l2)
{
    int distance[MAX][MAX];
    int i,j;
    int d,in,s;
    for(i=0;i<=l1;i++)
            distance[0][i]=i;
    for(i=1;i<=l2;i++)
            distance[i][0]=i;
    for(i=1;i<=l2;i++)
    {
                      for(j=1;j<=l1;j++)
                      {
                                        d=distance[i-1][j]+1;                    // change 1 to new weight of insertion... 
                                        in=distance[i][j-1]+1;                    //change 1 to new weight of deletion....
                                        s=distance[i-1][j-1]+(a[j-1]!=b[i-1]);   // * the (a[i-1]!=b[j-1]) with weight of substition...
                                        
                                        distance[i][j]=min(d,in,s);
                      }
    }
    /*for(int i=0;i<=l2;i++)
    {
            for(j=0;j<=l1;j++)
            {
                              printf("%d\t",distance[i][j]);
            }
            printf("\n");
    }*/
    return distance[l2][l1];
    
}

int main()
{
    int t;
    char s1[100],s2[100];
    scanf("%d",&t);
    while(t--)
    {
              scanf("%s %s",s1,s2);
              printf("%d\n",dis(s1,s2,strlen(s1),strlen(s2)));
    }
    return 0;  
}
