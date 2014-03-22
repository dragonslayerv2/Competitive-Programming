#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &imCompatable,int current,int pos)
{
	if(pos==imCompatable.size())
		return 0;
	
	int ans1=0;
	if(((1<<pos)&current)==0)
		ans1=1+solve(imCompatable,current|imCompatable[pos],pos+1);
	int ans2=solve(imCompatable,current,pos+1);
	return max(ans1,ans2);
}


int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<vector<int> > sets(m);
	for(int i=0;i<m;i++)
	{
		int size;
		scanf("%d",&size);
		sets[i].resize(size);
		
		for(int j=0;j<size;j++)
			scanf("%d",&sets[i][j]);
	}
	
	vector<int> imCompatable(m);
	
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			int i1=0;
			int j1=0;
			while(i1<sets[i].size()&&j1<sets[j].size())
			{
				if(sets[i][i1]<sets[j][j1])
					i1++;
				else if(sets[i][i1]>sets[j][j1])
					j1++;
				else
					break;
			}
			if(i1<sets[i].size()&&j1<sets[j].size())
			{
		//		cout<<i<<" not compatable with "<<j<<endl;
				imCompatable[i]|=1<<j;
				imCompatable[j]|=1<<i;
			}
		}
	}
	cout<<solve(imCompatable,0,0);
}
