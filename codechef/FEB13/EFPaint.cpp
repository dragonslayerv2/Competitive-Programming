#include<stdio.h>


int ins[2501][4],index=0;
char A[51][51];
int B[51][51];
 
void cleanB(int N)
{
for(int i=0;i<N;i++)
{
for(int j=0;j<N;j++)
{
B[i][j]=0;
}
}
}
void print(char ch,int N,int start,int end)
{
for(int i=start;i<end;i++)
{
for(int j=0;j<N;j++)
{
if(!B[i][j])
{
if(A[i][j]==ch)
{
int k,l,m;
for(k=j;A[i][k]==ch;k++){B[i][k]=1;}
for(l=i+1;l<end;l++)
{
int flag=1;
for(m=j;m<k;m++)
{
if(A[l][m]!=ch)
{
flag=0;
break;
}
}
if(!flag)
{
break;
}
}
for(int a=i+1;a<l;a++)
{
for(int b=j;b<k;b++)
{
B[a][b]=1;
}
}
ins[index][0]=i;
ins[index][1]=j;
ins[index][2]=l-1;
ins[index][3]=k-1;
index++;
j=k;
}
}
}
}
}
 
int main()
{
int N;
scanf("%d",&N);
getchar();
for(int i=0;i<N;i++)
{
scanf("%s",A[i]);
}
int min=5001,use=0;
int n=0;
while(n<=N)
{
index=0;
cleanB(N);
print('W',N,0,n);
print('B',N,n,N);
if(n!=0){index++;}
if(index<min)
{
min=index;
use=n;
}
n++;
}
index=0;
cleanB(N);
print('W',N,0,use);
print('B',N,use,N);
if(use!=0)
{printf("%d\n",index+1);}
else
{printf("%d\n",index);}
for(int i=0;i<index;i++)
{
printf("%d %d %d %d B\n",ins[i][0],ins[i][1],ins[i][2],ins[i][3]);
}
if(use!=0){printf("%d %d %d %d F\n",0,0,use-1,N-1);}

}
