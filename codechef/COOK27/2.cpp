#include<stdio.h>
#include<stdlib.h>
typedef double element;
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

inline int find(int low,int high,int pos[],int n)
{
    int x=0;
    int l=0;
    int f=n-1;

    int flag=0;
    int ps;
        while(1)
        {
                 ps=(l+f)/2;
                if(l>f) break;
                if(pos[ps]<=high&&pos[ps]>=low)
                                          {flag=1; break;}
                else if(pos[ps]<low)
                     l=ps+1;
                else
                    f=ps-1;
        }
    if(flag==0){ return 0;}
    else
    {

        if(ps==0&&ps==n-1)
        {
         return 1;
        }
        else if(ps==0)
        {
         return 1+(pos[ps+1]<=high&&pos[ps+1]>=low);
        }
        else if(ps==n-1)
             return 1+(pos[ps-1]<=high&&pos[ps-1]>=low);

        else if((pos[ps-1]<=high&&pos[ps-1]>=low)||(pos[ps+1]<=high&&pos[ps+1]>=low))
                                                                     return 2;
        else
            return 1;
    }


}
element recurse(int l,int f,int pos[],int n,element p)
{

     int c=find(l,f,pos,n);

     if(c==0)
             return 0;
     else if(f-l==1)
     {
               if(c==2) return element(1);
               else
                   return p;
     }

     else
     {

         element p1=recurse(l,l+(f-l)/2,pos,n,p);
         element p2=recurse(l+(f-l)/2+1,f,pos,n,p);

         return p1*(p2+(1-p2)*p)+(1-p1)*(p*p2);
     }
}

int main()
{
    int t;
    scanf("%d",&t);
    int pos[10001];
    while(t--)
    {
              int n,m;
              element p;
              scanf("%d %d %lf",&n,&m,&p);
              for(int i=0;i<m;i++)
              {
               scanf("%d",&pos[i]);
              }

              qsort (pos, m, sizeof(int), compare);

              printf("%.14lf\n",recurse(1,n,pos, m,p/100)*100);
    }
    return 0;
}
