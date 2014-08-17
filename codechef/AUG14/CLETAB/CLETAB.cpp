#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<climits>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		vector<int> currentTable(n,-1);
		
		vector<int> orders(m);
		for(int i=0;i<m;i++)
			cin>>orders[i];
		
		vector<int> nextLocation(m);
		vector<int> hashedLocation(500,INT_MAX);
		
		for(int i=m-1;i>=0;i--)
		{
			nextLocation[i]=hashedLocation[orders[i]];
			hashedLocation[orders[i]]=i;
		}
		
		int totalReplaced = 0;
		for(int i=0;i<orders.size();i++)
		{
			bool toReplace = true;
			int replacePosition = -1;
			
			for(int j=0;j<currentTable.size();j++){
				if(currentTable[j]==-1||orders[currentTable[j]]==orders[i])
				{
					
					toReplace = (currentTable[j]==-1);
					replacePosition=j;
					break;
				}
				if(replacePosition==-1||nextLocation[currentTable[j]]>nextLocation[currentTable[replacePosition]])
					replacePosition=j;
			}
			totalReplaced+=toReplace;
			currentTable[replacePosition]=i;
		}
		cout<<totalReplaced<<endl;
	}
}
