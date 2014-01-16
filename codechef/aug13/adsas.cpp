#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 100005

long long cumulative[MAX];
int array[MAX];
pair<int,int> range[MAX];
long long range_sum[MAX];

void fillrange(int n,int m)
{
	int i;
	cumulative[0]=0;
	for(i=1;i<=n;i++)
	{
		cumulative[i]=cumulative[i-1]+array[i];
	}

	for(i=0;i<m;i++)
	{
		range_sum[i]=cumulative[range[i].second]-cumulative[range[i].first-1];
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int m;
	scanf("%d",&m);
	int i;
	for( i=1;i<=n;i++)
		scanf("%d",&array[i]);
	
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&range[i].first,&range[i].second);
	} 
	sort(range,range+m);
	fillrange(n,m);


	int x;
	scanf("%d",&x);
	int ans=0;
	while(x--)
	{
		int pos;
		scanf("%d",&pos);
		pos=pos+ans;
		if(array[pos]!=0)
		{
			int i;
			array[pos]--;
			bool flag=false;
			for(i=0;i<m;i++)
			{
				if(range[i].first>pos)
				    break;
				if(pos>=range[i].first&&pos<=range[i].second)
				{
					range_sum[i]--;
					if(range_sum[i]==0)
					{
						flag=true;
						ans++;
					}	
				}	
			}
			
			if(flag)
			{
			int k=0;
			int m_temp=m;

			for(i=0;i<m&&k<m;i++)
			{

				k=i>k?i:k;
				while(range_sum[k]==0&&k<m)
				{
					k++;
				}
				if(k<m)
				{
					swap(range_sum[k],range_sum[i]);
					swap(range[k],range[i]);
					k++;
				}
			}
			int m=0;
			while(m<m_temp&&range_sum[m]!=0)
			    m++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

