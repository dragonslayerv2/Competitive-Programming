
#include<iostream>
#include<algorithm>
using namespace std;

#define MOD 747474747
#define D 5
#define MAXN 6666


//------------------------------------------------------------------------------
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

inline int readInt() 
{
	int flag=1;
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
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
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
struct point
{
	int x[D];
};

long long distance(point a,point b,int d)
{
	long long ans=0;
	for(int i=0;i<d;i++)
	{
		ans+=(a.x[i]-b.x[i])*(a.x[i]-b.x[i]);
	}
	return ans;
}
point points[MAXN];
//------------------------------------------------------------------------------

struct node
{
	int a,b;
	long long dist;
	inline bool operator >(const node &a,const node &b)
	{
		return a.dist>b.dist;
	}
};






int main()
{
	int t;
	t=readInt();
	while(t--)
	{	
		
		int n,d;
		n=readInt();
		d=readInt();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<d;j++)
			{
				points[i].x[j]=readInt();			
			}
		}
		int tvertex=0;
		for(int i=0;i<n;i++)
		{
			
			for(int j=i+1;j<n;j++)
			{
				vertex[tvertex].a=i;
				vertex[tvertex].b=j;
				vertex[tvertex].dist=distance(points[i],points[j],d);

				tvertex++;
			}      
		}
		
		sort(vertex,vertex+tvertex,cmp);
		
		makeset(vertices,n);
		
		long long ans=1;
		for(int i=0;i<tvertex;i++)
		{
			if(vertex[i].dist<=1) break;
			
			if(Union(vertices,vertex[i].a,vertex[i].b))
			{
				
				ans*=vertex[i].dist;
				ans=ans%MOD;
			}
		}	
		writeInt(ans);
		
		
	}
	return 0;
}
