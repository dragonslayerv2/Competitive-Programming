#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
#include<map>
using namespace std;

struct node{
	int count;
	int currentReferenceId;
	int currentCount;
	
	map<int,node *> next;
	node(){
		count=0;
		currentReferenceId=0;
	}
};

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int> > q(n,vector<int>(n-1));
		set<int> pos1;
		
		node *root = new node();
		
		for(int i=0;i<n;i++){
			node *currentNode=root;
			for(int j=0;j<n-1;j++){
				cin>>q[i][j];
				if(!currentNode->next[q[i][j]])
					currentNode->next[q[i][j]]=new node();
				currentNode=currentNode->next[q[i][j]];
					
				if(q[i][j]==1)
					pos1.insert(j);
					if(j+1<n)
						pos1.insert(j+1);
			}
			currentNode->count++;
		}
		vector<int> newArray(n);
		
		int currentReferenceId=0;
		
		for(int i=0;i<q.size();i++){
			bool isOk=true;
			for(set<int>::iterator j=pos1.begin();j!=pos1.end();j++)
			{
				currentReferenceId++;
				for(int k=0;k<n;k++){
					if(k==*j)
						newArray[k]=1;
					else if(k<*j)
						newArray[k]=q[i][k]+1;
					else
						newArray[k]=q[i][k-1]+1;
				}
				
				isOk=true;
				for(int i=1;i<=n;i++)
				{
					node *currentNode=root;
					for(int j=0;j<n;j++){
						int currentNumber;
						if(newArray[j]==i)
							continue;
						else if(newArray[j]<i)
							currentNumber=newArray[j];
						else
							currentNumber=newArray[j]-1;
							
						map<int,node *>::iterator nextNode=currentNode->next.find(currentNumber);
						if(nextNode!=currentNode->next.end())
							currentNode=nextNode->second;
						else {
							isOk=false;
							break;
						}
					}
					if(isOk){
						if(currentNode->currentReferenceId<currentReferenceId)
						{
							currentNode->currentReferenceId=currentReferenceId;
							currentNode->currentCount=currentNode->count;
						}
						if(currentNode->currentCount<=0)
						{
							isOk=false;
							break;
						}
						else
							currentNode->currentCount--;
					}
					else
						break;			
				}
				
				if(isOk){
					for(int i=0;i<newArray.size();i++)
						cout<<newArray[i]<<" ";		
					cout<<endl;
					break;
				}
			}
			if(isOk)
				break;	
		}
	}
}
