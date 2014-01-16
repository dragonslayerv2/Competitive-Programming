#include<stdio.h>
#include<stdlib.h>

#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

inline int readInt() 
{
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c=='\n'||c==' ') break;
                              n = n * 10 + c - '0';
    }
    return n;
}
 

inline void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     // buf[10] = 0;
     buf[10] = '\n';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}




#define M 20010
#define MAX 5010
typedef struct node
{
       int x,y;
       int cost;
}node;


int compare (const void * a, const void * b)
{
    return ( ((node*)a)->cost - ((node*)b)->cost );
}
int compare2 (const void * a, const void * b)
{
    return (  ((node*)b)->cost-((node*)a)->cost );
}




int main()
{
    int t;
    t=readInt();
    int i;
    int graph[MAX];
    
    while(t--)
    {
              
              int n,m1,m2;
              n=readInt();
              m1=readInt();
              m2=readInt();
              int nn=n;
              node company[M],chef[M];
              for(i=0;i<m1;i++)
              {
                      company[i].x=readInt();
                      company[i].y=readInt();
                      company[i].cost=readInt();
              }
              for(i=0;i<m2;i++)
              {       chef[i].x=readInt();
                      chef[i].y=readInt();
                      chef[i].cost=readInt();
              }
              
              qsort(  company, m1, sizeof(node), compare);
              qsort (chef, m2, sizeof(node), compare2);
              
              long long total=0;
              long long profit=0;
              
              
              for(i=0;i<n;i++)
                      graph[i]=i;
              
              int j;
              
              for(j=0;j<m2&&nn>1;j++)
              {
                      
                      if(graph[chef[j].x]!=graph[chef[j].y])
                      {                                     
                           nn--;
                           profit+=chef[j].cost;
                           int prev=graph[chef[j].x];
                           int nw=graph[chef[j].y];
                           for(i=0;i<n;i++)
                           {
                                           if(graph[i]==prev)
                                                             graph[i]=nw;
                                           
                                           
                           }
                      }
              }


              for(j=0;j<m1&&nn>1;j++)
              {
                                   
                      if(graph[company[j].x]!=graph[company[j].y])
                      {
                           nn--;
                           total+=company[j].cost;
                           int prev=graph[company[j].x];
                           int nw=graph[company[j].y];
                           for(i=0;i<n;i++)
                           {
                                           if(graph[i]==prev)
                                                             graph[i]=nw;          
                           }
                      }
              }
        
              if(nn>1)
                    printf("Impossible\n");
              else
                    printf("%lld %lld\n",profit,profit+total);  
    }
    
    return 0;
}
