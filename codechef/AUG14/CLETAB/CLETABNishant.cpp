#include <stdio.h>
int main()
{
    int t,m,n,i,j,f=0,k;int c[500],tables[500],cst=0,vis[500],count,max,maxel;
    scanf("%d",&t);
    while(t--)
    {
        f=0;
        count=0;max=0;maxel=0;cst=0;
        for(i=0;i<401;i++)
            vis[i]=0;
        scanf(" %d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&c[i]);
        }
        //cst=1;
        for(i=0;i<m;i++)
        {//printf("!!%d\n",c[i]);
            if(vis[c[i]]==0){
                if(cst<n)
                {
                    tables[cst]=c[i];
                    vis[c[i]]=1;
                    cst+=1;
                    count+=1;
                }

                else
                {//printf("\n");
                    //for(j=0;j<n;j++)
                    //{
                       // printf("@%d@",tables[j]);}
                    for(j=0;j<n;j++)
                    {
                        //printf("@%d@",tables[j]);
                        f=0;
                        for(k=i+1;k<m;k++)
                        {
                            if(c[k]==tables[j]){f=1;
                                if((k-i)>max){
                                    max=k-i;maxel=j;}}
                        }
                        if(!f){
                                maxel=j;break;}
                    }
                    max=0;f=0;
               //   printf("\n##%d %d %d\n",tables[maxel],c[i],count+1);
                    vis[tables[maxel]]=0;
                    tables[maxel]=c[i];
                    vis[c[i]]=1;
                    count+=1;
                }
            }
        }printf("%d\n",count);
    }
    return 0;
}
