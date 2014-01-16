#include<stdio.h>
#include<string.h>
char ins[100][100];
char temp[100];
char street[100][100];

#define right "Right"
#define left "Left"
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int n;
              scanf("%d",&n);
              for(int i=0;i<n;i++)
              {
                      scanf("%s %s ",ins[i],temp);
                      gets(street[i]);
              }
              for(int i=n-1;i>=0;i--)
              {
                      if(i==n-1)
                      {
                                printf("Begin on %s\n",street[i]);
                      }
                      else
                      {
                                
                               if(ins[i+1][0]=='L'||ins[i+1][0]=='l')
                                {
                                                         printf(right);
                                }
                                else
                                                         printf(left);
                                printf(" on %s\n",street[i]);
                      }
              }
              
    }
    return 0;
}
