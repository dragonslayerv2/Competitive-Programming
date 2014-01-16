//Some form of brute force attack...:)



#include<stdio.h>
#define MAX 100
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
