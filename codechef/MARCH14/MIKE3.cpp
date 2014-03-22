#include<stdio.h>
#include<vector>
using namespace std;


pair<bool,int> solve(vector<vector<int> > &sets, vector<int> &current, int pos,int current,int intuition)
{
	if(pos==sets.size())
		return make_pair(true,0);
	else
	{
		//if I dont take..
		pair<bool,int> ans1=solve(sets,current,pos+1);
		//else
		bool canTake=true;
		for(int i=0;i<sets[pos].size();i++)
		{
			current[sets[pos][i]]++;
			if(current[sets[pos][i]]>1)
				canTake=false;
		}
		pair<bool,int> ans2=make_pair(false,0);
		
		for(int i=0;i<sets[pos].size();i++)
			current[sets[pos][i]]--;
		
		if(!canTake)
			return ans1;
		else
			return max(make_pair(ans2.first,ans2.second+1),ans1);	
	}	
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
	vector<int> temp(n+1);
	printf("%d",solve(sets,temp0,m).second);
}
