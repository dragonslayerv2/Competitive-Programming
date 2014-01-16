/*-------------------------Test cases
5 4 5 3
1 0 2
0 3 1
4 3 3
3 2 1
2 1 2
3 3 0 20
4 3 3 25
1 0 0 10
*/



#include<stdio.h>
#include<string.h>
#define MAX 20

#define UP 0
#define DOWN 2
#define LEFT 3
#define RIGHT 1 

#define bndir(pdir) ((pdir+1)%4)
#define endir(pdir) ((pdir+2)%4)


int n,m,q,w;


int solve(int alley[MAX][MAX],int x,int y,int dir,float speed)
{
   /// printf("at %d %d\talley[x][y]=%d\tdir=%d\tspeed=%f\n",x,y,alley[y][x],dir,speed);
    if(speed<=(float)0) return 0;
    if(x<0||y<0||x>=m||y>=n)
    {
    
                           return solve(alley,x<0?0:(x>=m?m-1:x),y<0?0:(y>=n?n-1:y),endir(dir),speed);
    }
    if(alley[y][x]==-1)
    {
                       alley[y][x]=0;
                       return 1+solve(alley,dir==LEFT?x-1:(dir==RIGHT)?x+1:x,dir==UP?y-1:(dir==DOWN)?y+1:y,dir,speed-1.0);
    }
    if(alley[y][x]==0)
    {
                       return solve(alley,dir==LEFT?x-1:((dir==RIGHT)?x+1:x),dir==UP?y-1:((dir==DOWN)?y+1:y),dir,speed-0.5);
    }

    return alley[y][x]+solve(alley,bndir(dir)==LEFT?x-1:((bndir(dir)==RIGHT)?x+1:x),bndir(dir)==UP?y-1:((bndir(dir)==DOWN)?y+1:y),bndir(dir),speed-1.5);
}

inline void reset(int alley[MAX][MAX],int temp[MAX][MAX])
{
       for(int i=0;i<MAX;i++)
       {
               for(int j=0;j<MAX;j++)
               {
                temp[i][j]=alley[i][j];
               }
       }
}
int main()
{
    int alley[MAX][MAX];
    int temp[MAX][MAX];
    memset(alley,-1,sizeof(alley));
    
    
    scanf("%d %d %d %d",&m,&n,&q,&w);
    
    int x,y,score;
    for(int i=0;i<q;i++)
    {
            scanf("%d %d %d",&x,&y,&score);
            alley[y][x]=score;
    }
    int dir,speed;
    while(w--)
    {
              scanf("%d %d %d %d",&x,&y,&dir,&speed);
              reset(alley,temp);
              printf("%d\n",solve(temp,x,y,dir,speed));
              
    }
    return 0;   
}
