/*
  Name: Levenshtein Distance
  Copyright: 
  Author: Shobhit Saxena
  Date: 15/11/12 16:09
  Description: This is a brute force version of edit distance problem. 
               The cost associated with each edit is 
               ins for insert
               del for deletion
               subs for substition.
               Complexity = O(3^n)
  A dynamic solution to this problem also exist. its complexity is O(l1.l2).
  where l1 and l2 are the length of two strings respectively.
*/



#include<stdio.h>
#include<string.h>
#define ins 1
#define del 1
#define subs 1

#define min(a,b,c) (a<b?a<c?a:c:b<c?b:c)



int dis(char *a,char *b,int l1,int l2)
{
    if(l1==0&&l2==0) return 0;
    else if(l1==0) return l2;
    else if(l2==0) return l1;
    else
    {
        int d=dis(a,b,l1-1,l2)+ins;
        int i=dis(a,b,l1,l2-1)+del;
        int s=dis(a,b,l1-1,l2-1)+subs*(a[l1-1]!=b[l2-1]);
        return min(d,i,s);
    }
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
