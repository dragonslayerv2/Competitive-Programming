#include<stdio.h>
#include<limits.h>
inline void swap(int &a,int &b)
{
       int temp=a;
       a=b;
       b=temp;
}

 int check(int a[],int b[],int n)
{
       int flag=0;
       for(int i=0;i<n;i++)
       {
               if(a[i]!=b[i])
               {
                             flag=1;
                             return 0;
               }
       }
       return 1;
}

int recurse(int box[],int solution[],int n,int x)
{
    if(check(box,solution,n)==1)
                                return 0;
    int min=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
            if(i==x)
            {
                    continue;
            }
            swap(box[i],box[i+1]);
            int c=recurse(box,solution,n,i);
            if(c<min) min=c;
            swap(box[i],box[i+1]);
    }
    return 1+min;
}

int main()
{
    int t,n;
    int box[100001];
    int solution[100001];
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
              for(int i=0;i<n;i++)
              {
                      scanf("%d",&box[i]);
              }
              
              for(int i=0;i<n;i++)
              {
                      scanf("%d",&solution[i]);
              }
              printf("%d\n",recurse(box,solution,n,-1));
    }
    return 0;
}
