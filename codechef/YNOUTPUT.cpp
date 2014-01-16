#include<stdio.h>
#include<string.h>

#define MAX 110

int flags[MAX][MAX/32+1];

#define isSet(i,n) (flags[i][n>>5]&(1<<(n&31)))
#define unset(i,n) flags[i][n>>5] &= ~(1<<(n&31))
#define set(i,n) flags[i][n>>5]|=(1<<(n&31))

inline int compare(int i,int j)
{
       if((flags[i][0]==flags[j][0])&&(flags[i][1]==flags[j][1])&&(flags[i][2]==flags[j][2])&&(flags[i][3]==flags[j][3]))   
                       return 1;
       return 0;
}

int main()
{
    int i,j,a,b;
    memset(flags,0,sizeof(flags));
    
    int t;
    scanf("%d",&t);
    
    char string[5];
    for(i=0;i<t;i++)
    {
            for(j=0;j<t;j++)
            {
                    scanf("%s",string);
                    if(string[0]=='Y') set(i,j);           
            }                
    }    
    
    int output[4]={0,0,0,0};
    
    for(i=0;i<t;i++)
    {
            
            int flag=1;
            if(isSet(i,i))
            {
                      
                      int a,b;
    
                   for(j=0;j<i;j++)
                           if(isSet(i,j)||compare(i,j))
                                 {flag=0;break;}
                   
                   if(flag==1)
                   {
                              
                    for(j=i+1;j<t;j++)
                    {
                         
                            a=isSet(i,j);
                           b=compare(i,j);
                           if((a&&!b)||(!a&&b))
                                    {flag=0;break;}    
                           else if(a)
                           {
                                                       output[j>>5]|=(1<<(j&31));  
                           }
                    }
                   }
                   
                   if(flag==0)
                          {output[0]=output[1]=output[2]=output[3]=0;    continue;   }
                   else if(flag==1)
                   {
                    output[i>>5]|=(1<<(i&31));
                    break;
                   }                                       
            }
    }
    for(i=0;i<t;i++)
    {
            if((output[i>>5]&(1<<(i&31)))) printf("YES\n");
            else printf("NO\n");
    }
    return 0;
}
