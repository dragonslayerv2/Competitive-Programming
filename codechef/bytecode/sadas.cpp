#include<iostream>
using namespace std;

const int size=600;

#define TRUE 0
#define FALSE 1

struct jewels
{
       long long jewels;
       int flag;
}

int a[size][size];
long long b[510][510];
char flag[510][510];

int m,n;

long long recurse(int i,int j)
{
    
    if((i==m-1)&&(j==n-1)) return 0;
    if(i>=m||j>=n||a[i][j]<0) {return -100000001;}
    if(c[i][j]!=-1){return b[i][j];} 
    
    long long x=recurse(i,j+1);
    long long y=recurse(i+1,j);
    
    
    if(x==-100000001&&y==-100000001) return -100000001;    

    long long negative=0;
    if(i!=0&&j!=0)
    {
                  if(a[i-1][j-1]<0&&i>=0&&j>=0) negative+=a[i-1][j-1];
                  if(a[i-1][j]<0&&i>=0)         negative+=a[i-1][j];
                   if(a[i-1][j+1]<0&&i>=0&&j<n)  negative+=a[i-1][j+1];
                    if(a[i][j-1]<0&&j>=0)         negative+=a[i][j-1];
                        if(a[i][j+1]<0&&j<n)          negative+=a[i][j+1];
                        if(a[i+1][j-1]<0&&j>=0&&i<m)  negative+=a[i+1][j-1];
                           if(a[i+1][j]<0&&i<m)          negative+=a[i+1][j];
                           if(a[i+1][j+1]<0&&j<n&&i<m)   negative+=a[i+1][j+1];
    }
    
    long long jewels=a[i][j];
    if(x==-100000001) jewels+=y+negative;
    else if(y==-100000001) jewels+=x+negative;
    else jewels=jewels+(x>y?x:y)+negative;
    
    b[i][j]=jewels;
    c[i][j]=1;
    return jewels;
}

int main()
{
          char temp;
         
          cin>>m>>temp>>n;
          
          int i,j;
          for(int i=0;i<m;i++)
          {
                  for(int j=0;j<n;j++)
                  {
                           c[i][j]='F';
                           if(j==n-1) cin>>a[i][j];
                           else cin>>a[i][j]>>temp;
                   }
          }

          cout<<recurse(0,0);
 //       end=clock();
   //     printf("\n%f",(float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
