#include<stdio.h>
int b[15][15],ans,m,n;
void solve(int x,int y,int d,float s)
{
     
  //  printf("at %d %d\talley[x][y]=%d\tdir=%d\tspeed=%f\n",x,y,b[y][x],d,s);
if(s<=0)
return;
if(x<0)
{
d=1;
x=0;
}
if(y<0)
{
d=2;
y=0;
}
if(x>=m)
{
d=3;
x=m-1;
}
if(y>=n)
{
d=0;
y=n-1;
}
if(b[y][x]==-1)
{ ans++,b[y][x]=0;
if(d==0)
{solve(x,y-1,0,s-1);return;}
else if(d==1)
{solve(x+1,y,1,s-1);return;}
else if(d==2)
{solve(x,y+1,2,s-1);return;}
else
{solve(x-1,y,3,s-1);return;}
}
else if(b[y][x]==0)
{
if(d==0)
{solve(x,y-1,0,s-0.5);return;}
else if(d==1)
{solve(x+1,y,1,s-0.5);return;}
else if(d==2)
{solve(x,y+1,2,s-0.5);return;}
else
{solve(x-1,y,3,s-0.5);return;}
}
else
{
ans+=b[y][x];
if(d==0)
{solve(x+1,y,1,s-1.5);return;}
else if(d==1)
{solve(x,y+1,2,s-1.5);return;}
else if(d==2)
{solve(x-1,y,3,s-1.5);return;}
else
{solve(x,y-1,0,s-1.5);return;}
}
}
 
int main()
{
int q,w,a[15][15],i,j,s,d,x,y,p;
scanf("%d %d %d %d",&m,&n,&q,&w);
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
a[i][j]=-1;
}
while(q--)
{
scanf("%d %d %d",&x,&y,&p);
a[y][x]=p;
}
while(w--)
{
ans=0;
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
b[i][j]=a[i][j];
}
scanf("%d %d %d %d",&x,&y,&d,&s);
solve(x,y,d,s);
printf("%d\n",ans);
}
return 0;
}
