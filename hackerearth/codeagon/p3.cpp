#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<list>
using namespace std;

int main(){
	int w;
	cin>>w;
	vector<string> strings(w);
	for(int i=0;i<w;i++)
		cin>>strings[i];
	map<char,int> characters;
	map<char,bool> isReferred;
	
	vector<list<char> > graph(200);
	for(int i=0;i<w-1;i++){
		for(int j=0;j<min(strings[i].size(),strings[i+1].size());j++)
		{
			characters[strings[i][j]]=0; 
			if(strings[i][j]!=strings[i+1][j]){
				graph[strings[i][j]].push_back(strings[i+1][j]);
				isReferred[strings[i+1][j]]=true;
				break;
			}
		}
	}
	
	queue<int> Q;
	char notReferred;
	for(map<char,int>::iterator i = characters.begin();i!=characters.end();i++)
		if(!isReferred[i->first]){
			notReferred = i->first;
			
	
		}
	characters[notReferred]=0;
	Q.push(notReferred);
	while(!Q.empty()){
		int top = Q.front();
		Q.pop();
		for(list<char>::iterator i = graph[top].begin();i!=graph[top].end();i++)	{
			Q.push(*i);		
			characters[*i]=characters[top]+1;
		}
	}
	
	for(int i=0;i<characters.size();i++){
		for(map<char,int>::iterator j = characters.begin();j!=characters.end();j++)
		{
			vector<char> sameRank;
			if(j->second==i)
				sameRank.push_back(j->first);
			sort(sameRank.begin(),sameRank.end());	
			for(int k=0;k<sameRank.size();k++)
				cout<<sameRank[k];
			cout<<endl;
		}
	}
}
