#include<stdio.h>
#include<string.h>
#define MOD 1000000007
#define MAX 1000000000
#define X 'X'
#define Y 'Y'
#define Z 'Z'
static int count=0;

int ans[MAX/3];


void dycksword(int l,int k,int lx=0,int ly=0,int lz=0,int x=0,int y=0,int z=0,int i=0)
{
   // printf("hi..");
    if(l==0) return;
    int count1=count;
    if(ly==0&&lz==0&&ans[lx])
    {
        count+=ans[lx];
        count%=MOD;
    }

    if(i==l)
    {
        count=count+1;
        if(count>=MOD) count%=MOD;
    }
     else if(i==0)
     {
             dycksword(l,k,lx+1,ly,lz,l/3-1,1,0,i+1);
     }
     else if(x&&!y&&!z)
     {
        if(lx-ly<k)
            dycksword(l,k,lx+1,ly,lz,x-1,y+1,z,i+1);

     }
     else if(!x&&y&&!z)
     {
         if(ly-lz<k)
            dycksword(l,k,lx,ly+1,lz,x,y-1,z+1,i+1);
     }
     else if(!x&&!y&&z)
         dycksword(l,k,lx,ly,lz+1,x,y,z-1,i+1);

     else if(x&&y&&!z)
     {
         if(lx-ly<k)
            dycksword(l,k,lx+1,ly,lz,x-1,y+1,z,i+1);

         if(ly-lz<k)
            dycksword(l,k,lx,ly+1,lz,x,y-1,z+1,i+1);
     }

     else if(!x&&y&&z)
     {
         dycksword(l,k,lx,ly,lz+1,x,y,z-1,i+1);
         if(ly-lz<k)
            dycksword(l,k,lx,ly+1,lz,x,y-1,z+1,i+1);
     }

     else if(x&&!y&&z)
     {
         dycksword(l,k,lx,ly,lz+1,x,y,z-1,i+1);
         if(lx-ly<k)
            dycksword(l,k,lx+1,ly,lz,x-1,y+1,z,i+1);
     }
     else if(x&&y&&z)
     {
         if(ly-lz<k)
            dycksword(l,k,lx,ly+1,lz,x,y-1,z+1,i+1);

         dycksword(l,k,lx,ly,lz+1,x,y,z-1,i+1);

         if(lx-ly<k)
            dycksword(l,k,lx+1,ly,lz,x-1,y+1,z,i+1);
     }

    if(ly==0&&lz==0&&!ans[lx])
        ans[lx]=(MOD+count-count1)%MOD;
}
int main()
{

    int l,k;
    scanf("%d%d",&l,&k);
    if(k%3) printf("Error!! k must be a multiple of 3");
    else
    {
        dycksword(k,l);
        printf("%d",count);
    }
    return 0;
}
