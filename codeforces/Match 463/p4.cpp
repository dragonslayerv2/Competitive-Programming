#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<vector<int> > permutations(k,vector<int>(n));
	
	for(int i=0;i<k;i++)
		for(int j=0;j<n;j++){
			cin>>permutations[i][j];
			permutations[i][j]--;
		}
		
	vector<vector<int> > positions(k,vector<int>(n));
	
	for(int i=0;i<k;i++)
		for(int j=0;j<n;j++)
			positions[i][permutations[i][j]]=j;
			
				
	
}
