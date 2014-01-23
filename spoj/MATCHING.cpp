/*
+	Name: Maximum Bipartite Matching
+	Copyright: 
+	Author: Shobhit Saxena
+	Date: 20/01/14 21:34
+	Description: This algorithm uses BFS to find the maximum matching of a Bipartite Graph.
+				 Uses an O(VE) algorithm. 
+				 Uses BFS for finding augmenting paths
+*/
 
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<map>
using namespace std;

typedef pair<vector<list<int> >,vector<list<int> > > bipartiteGraph;

//#define DEBUG

int bipartiteMatching(const bipartiteGraph &G)
{
 	#define UNMATCHED -1
	
 	vector<int> Lmatch(G.first.size() ,UNMATCHED);
 	vector<int> Rmatch(G.second.size(),UNMATCHED);
 	
 	while(1)
 	{
 		vector<int> augmentingPathEnd;
 
 		queue<pair<int,char> > Q;
 		vector<int> Lparent(Lmatch.size(),UNMATCHED);
 		vector<int> Rparent(Rmatch.size(),UNMATCHED);
 		
 		for(int i=0;i<Lmatch.size();i++)
 		{
 			if(Lmatch[i]==UNMATCHED) 
 			{	
 				Q.push(make_pair(i,'L'));
 				Lparent[i]=-2;
 			}
 		}
 		
 		while(!Q.empty())
 		{
 			pair<int,char> current=Q.front();
 			Q.pop();
 			
 			if(current.second=='L')
 			{
 				for(list<int>::const_iterator i=G.first[current.first].begin();i!=G.first[current.first].end();i++)
 					if(Rparent[*i]==UNMATCHED&&(*i)!=Lmatch[current.first])
 					{
 						Rparent[*i]=current.first;
 						Q.push(make_pair(*i,'R'));
 					}
 			}
 			else
 			{
 				if(Rmatch[current.first]==UNMATCHED)
 				{
 					augmentingPathEnd.push_back(current.first);
 				}
 				else
 				{
 					if(Lparent[Rmatch[current.first]]==UNMATCHED)
 					{
 						Lparent[Rmatch[current.first]]=current.first; // no need to check as Left nodes are not pushed multiple times
 						Q.push(make_pair(Rmatch[current.first],'L'));
 					}
 				}
 			}
 		}
 
 		//----------------
 		if(augmentingPathEnd.size())
 		{
 			for(int i=0;i<augmentingPathEnd.size();i++)
 			{
 				while(1)
 				{
 					Rmatch[augmentingPathEnd[i]]=Rparent[augmentingPathEnd[i]];
 					if(Lmatch[Rmatch[augmentingPathEnd[i]]]!=UNMATCHED)
 							Rmatch[Lmatch[Rmatch[augmentingPathEnd[i]]]]=UNMATCHED;
 					Lmatch[Rmatch[augmentingPathEnd[i]]]=augmentingPathEnd[i];
 				
 					augmentingPathEnd[i]=Rparent[augmentingPathEnd[i]];
 					if(Lparent[augmentingPathEnd[i]]==-2)
 						break;
 					else
 						augmentingPathEnd[i]=Lparent[augmentingPathEnd[i]];
 				}
 			}
 	 	}
 		else
 			break;
 	}
 	int count=0;
 	for(int i=0;i<Lmatch.size();i++)
 		if(Lmatch[i]!=UNMATCHED)
 			count++;
	return count;
 }
 
 int main()
 {
 	//ios_base::sync_with_stdio(false);
 	int lSize,rSize;
 	cin>>lSize>>rSize;
 	bipartiteGraph G;
 	G.first.resize(lSize);
 	G.second.resize(rSize);
 	
 	int e;
 	cin>>e;
 	while(e--)
 	{
  	int a,b;
 		
 	 	cin>>a>>b;
 	 	a--;
 	 	b--;
 	 	G.first[a].push_back(b);
 		G.second[b].push_back(a);
 	}
 	cout<<bipartiteMatching(G);
} 

