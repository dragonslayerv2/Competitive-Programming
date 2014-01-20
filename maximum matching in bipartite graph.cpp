+/*
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
 
 vector<int> bipartiteMatching(const bipartiteGraph &G)
 {
 #ifdef DEBUG
 cout<<"Function Called"<<endl;
 #endif
 
 	#define UNMATCHED -1
 	
 	vector<int> Lmatch(G.first.size() ,UNMATCHED);
 	vector<int> Rmatch(G.second.size(),UNMATCHED);
 	
 	while(1)
 	{
 #ifdef DEBUG
 for(int i=0;i<Lmatch.size();i++)
 	cout<<Lmatch[i]<<" ";
 cout<<endl;
 for(int i=0;i<Rmatch.size();i++)
 	cout<<Rmatch[i]<<" ";
 cout<<endl;
 cout<<"Trying to find the augmenting path"<<endl;
 #endif
 		int augmentingPathEnd=-1;
 
 		// ---------bfs-------------
 #ifdef DEBUG
 cout<<"Started BFS"<<endl;
 #endif
 
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
 					augmentingPathEnd=current.first;
 					break;
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
 
 #ifdef DEBUG
 cout<<"BFS complete"<<endl;
 #endif
 		//----------------
 		if(augmentingPathEnd!=-1)
 		{
 #ifdef DEBUG
 cout<<"Augmenting Path found"<<endl;
 cout<<"Updating Vertices"<<endl;
 #endif
 			while(1)
 			{
 				Rmatch[augmentingPathEnd]=Rparent[augmentingPathEnd];
 				if(Lmatch[Rmatch[augmentingPathEnd]]!=UNMATCHED)
 					Rmatch[Lmatch[Rmatch[augmentingPathEnd]]]=UNMATCHED;
 				Lmatch[Rmatch[augmentingPathEnd]]=augmentingPathEnd;
 			
 				augmentingPathEnd=Rparent[augmentingPathEnd];
 				if(Lparent[augmentingPathEnd]==-2)
 					break;
 				else
 					augmentingPathEnd=Lparent[augmentingPathEnd];
 			}
 #ifdef DEBUG
 cout<<"Updation Done";
 #endif
 	 	}
 		else
 			break;
 	}
 #ifdef DEBUG
 cout<<"No augmenting Path Found"<<"Ending"<<endl;
 #endif	
 	return Lmatch;
 }
 
 int main()
 {
 	freopen("test.txt","r",stdin);
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
 	 	G.first[a].push_back(b);
 		G.second[b].push_back(a);
 	}
 	vector<int> matching=bipartiteMatching(G);
 	for(int i=0;i<matching.size();i++)
 		cout<<i<<" "<<matching[i]<<endl;
} 

