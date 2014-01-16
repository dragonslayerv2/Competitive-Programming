//#include<math.h>
#include<iostream.h>
//#include<conio.h>
#define max(a,b) ((a>b)?a:b)
const int size=501;
long long min=-999999999;
long int r,c,input[size][size];
long long pick[size][size],a[size][size];
long long solve(long int X,long int Y)
{
//cout<<"("<<X<<","<<Y<<")"<<endl;
if(X==(r-1)&&Y==(c-1))
{
return a[r-1][c-1];
}
if(pick[X][Y]!=-1)
{
return pick[X][Y];
}
else
{
long long t1,t2;
if(X<(r-1)){t1=solve(X+1,Y);}
else{t1=min;}
if(Y<(c-1)){t2=solve(X,Y+1);}
else{t2=min;}
long long t=a[X][Y]+max(t1,t2);
pick[X][Y]=t;
return t;
}
}
int main()
{
min*=500;
//cout<<min;
pick[0][0]=0;
char temp;
scanf("%d%c%d",&r,&temp,&c);
if(r==0||c==0){cout<<"0";return 0;}
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
pick[i][j]=-1;
a[i][j]=0;
scanf("%d",&input[i][j]);
if(j<c-1){scanf("%c",&temp);}
}
}
//traverse
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
if(input[i][j]>=0)
{
a[i][j]+=input[i][j];
}
else if(input[i][j]<0)
{
for(int k=i-1;k<=i+1;k++)
{
for(int m=j-1;m<=j+1;m++)
{
if((k>=0&&k<r)&&(m>=0&&m<c)&&(a[k][m]!=min))
{
//cout<<a[k][m]<<" "<<input[i][j]<<"\n";
if((k==0&&m==0)||(k==r-1&&m==c-1)){continue;}
else{a[k][m]+=input[i][j];}
}
}
}
a[i][j]=min;
}
}
}

cout<<solve(0,0);

}