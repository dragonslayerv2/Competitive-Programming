#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

void print_path(pair<int,int> final)
{
	pair<int,int> current=make_pair(0,0);
	while(current!=final)
	{
		cout<<"("<<current.first+1<<","<<current.second+1<<") ";
		if(current.first<final.first)
			current.first++;
		else
			current.second++;
	}
	cout<<"("<<final.first+1<<","<<final.second+1<<")";
	cout<<endl;
}
int main()
{
//	freopen("test.txt","r",stdin);
	int n,m,k;
	cin>>n>>m>>k;
	
	queue<pair<int,int> > Q;
	
	map<int,pair<int,int> > pos;
	map<pair<int,int>,bool > used;
	int count=0;
	Q.push(make_pair(0,0));
	while(count<k)
	{
		pair<int,int> current=Q.front();
		Q.pop();
		if(!used[current])
		{
			pos[count]=current;
			used[current]=true;
			count++;
			if(current.first+1<n)
				Q.push(make_pair(current.first+1,current.second));
			if(current.second+1<m)
				Q.push(make_pair(current.first,current.second+1));
		}
	}
	int penalty=0;
	for(int i=0;i<pos.size();i++)
	{
		
		penalty+=(pos[i].first+pos[i].second)+1;
	}
	
	cout<<penalty<<endl;
	for(int i=pos.size()-1;i>=0;i--)
		print_path(pos[i]);
	
}
