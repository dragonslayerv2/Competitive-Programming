#include<stdio.h>
#include<stdlib.h>


#define GETCHAR getchar//_unlocked
#define PUTCHAR putchar//_unlocked

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

int compare (const void * a, const void * b)
{
    return ( *(int*)b - *(int*)a );
}

int binarysearch(int *a,int *S,int n,int k,int i,int u)
{
	int l=(i+u)/2;
	int value=l*(a[i])-S[i+l]-S[i];
	if(value==k) return l;
	if(value<k&&((l+1)*(a[i])-S[i+l+1]-S[i])>k) return l;
	else if(value<k) 	return binarysearch(a,S,n,k,l+1,u);
	else if(value>k)	return binarysearch(a,S,n,k,i,l-1);
}


int main()
{	
	int a[100001];
	int S[100001]={0};
	int n,k;
	//scanf("%d %d",&n,&k);
	n=readInt();
	k=readInt();
	for(int i=0;i<n;i++)
	{
		a[i]=readInt();
	}
	
	qsort (a,n, sizeof(int), compare);
	
	int x=0;
	for(int i=0;i<n;i++)
	{
		S[i]=x+a[i];
		x=S[i];
		//printf("%d ",S[i]);
	}
	
	int maxCount=0;
	for(int i=0;i<n;i++)
	{
		int count=binarysearch(a,S,n,k,i,n-1);
		if(count>maxCount)
			count=maxCount;
	}
	writeInt(maxCount);
	//printf("%d\n",maxCount);
	return 0;
}

