#include<iostream>
#include<climits>
#include<algorithm>
#include<cstdlib>
using namespace std; //-------------------------------------------------

struct s
{
int x,y;
};

inline int compare(const void *a,const void *b)
{
if((((struct s *)a)->x)==(((struct s *)b)->x))
{
return ((struct s *)b)->y-((struct s *)a)->y;
//cout<<"l";
}
return ((struct s *)a)->x-((struct s *)b)->x;
}
int main()
{
int n,m,p;
cin>>n>>m>>p;
struct s S[p+1];
for(int i=0;i<p;i++)
{
cin>>S[i].x>>S[i].y;
}
qsort(S,p,sizeof(S[0]),compare);

int index=0;
int prev=0;
int curr=0;
int j=0;
int arr[m+1];
for(int i=1;i<=m;i++)
arr[i]=i;
int start=0,end=0;
for(int i=0;i<n;i++)
{
/*for(int i=1;i<=m;i++)
cout<<arr[i]<<" ";
cout<<endl;*/
int ans=m-1;
while(S[index].x==i+1)
{
int j=S[index].y;
if(index-1>=0 && S[index-1].x!=S[index].x)
start=index;
end=index;
arr[j]++;
if(j==m)
{
ans++;
}
if(j==1)
{
ans--;
}
if(j<m && arr[j]>arr[j+1])
{
ans=-1;
index++;
break;
}
index++;
}
if(m==1)
cout<<"0\n";
else
cout<<ans<<endl;
for(int k=start;k<=end;k++)
{
//	cout<<"k";
arr[S[k].y]=S[k].y;}
}
}
