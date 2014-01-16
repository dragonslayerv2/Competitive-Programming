#include<stdio.h>
#include<ctype.h>

int p;
int n;
char papers[1000][1000];
char authors[1000][1000];
int pos[1000][1000];
int k[1000];
int m[1000];
int e;
int number[1000];

int substring(char *a,char *b)
{
    int i=0;
    int j=0;
    int flag=0;
    while(1)
    {
            if(a[i]==NULL)
            {
                          return 1;
            }
            if(b[j]==NULL)
                           break;
            if(tolower(a[i])==tolower(b[j]))
            {
                          i++;
            }        
            else
            {
                     if(i!=0)
                             {i=0;j--;}                
            }
            j++;
    }
    return 0;
}
void checkauthors()
{
        for(int i=0;i<n;i++)
        {
                k[i]=0;
                for(int j=0;j<p;j++)
                {
                        if(substring(authors[i],papers[j]))
                        {
                                                           pos[i][k[i]++]=j;
                        }
                }
                
        }
        e=0;
        for(int i=0;i<p;i++)
        {
                if(substring("Erdos, P.",papers[i]))
                {
                                                m[e++]=i;                                    
                }
        }
        if(e==0)
                {
                                                for(int i=0;i<n;i++)
                                                {
                                                        number[i]=-1;
                                                }
                                                return;
                }
        for(int i=0;i<n;i++)
        {
                number[i]=-1;
                int x=0,y=0;
                while(1)
                {
                        if(x==e||y==k[i]) break;
                        if(m[x]==pos[i][y])
                        {
                                        number[i]=1;
                                        break;
                        }
                        else if(m[x]<pos[i][y])
                                            x++;
                        else
                                            y++;
                }
                if(number[i]==1) continue;
                
                for(int j=0;j<n;j++)
                {       if(number[j]==-1) continue;
                        if(number[i]!=-1&&number[i]<number[j]) continue;
                        int x=0,y=0;
                        if(j==i)
                        {
                                j++;
                                continue;
                        }
                        
                        while(1)
                        {
                                if(x==k[j]||y==k[i]) break;
                        if(pos[j][x]==pos[i][y])
                        {
                                        int newnumber=number[j]+1;
                                        int newnumber2=number[i]+1;
                                        if(number[i]==-1) {number[i]=newnumber;break;}
                                        else if(number[i]>newnumber&&newnumber!=0) number[i]=newnumber;
                                        else if(number[j]>newnumber2&&newnumber2!=0) number[j]=newnumber2;
                                        break;
                        }
                        else if(pos[j][x]<pos[i][y])
                                            x++;
                        else
                                            y++;
                                            }
                }
                
        }
        
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
            
            scanf("%d %d",&p,&n);
            for(int j=0;j<p;j++)
            {
                    fflush(stdin);
                    gets(papers[j]);
            }
            for(int j=0;j<n;j++)
            {
                    fflush(stdin);
                    gets(authors[j]);
            }
            
            checkauthors();    
            
            printf("Scenario %d\n",i);
            for(int j=0;j<n;j++)
            {
                    if(number[j]==-1)
                                     printf("%s infinity\n",authors[j]);        
                    else
                                     printf("%s %d\n",authors[j],number[j]);        
            }            
    }
    return 0;
}
