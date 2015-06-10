#include<iostream>
#include<vector>
#include<map>
using namespace std;


int present[500];
int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<500;i++)
			present[i]=0;
			
		vector<int> entry(n);
		vector<int> exit(n);
		map<int,int> points;
		for(int i=0;i<n;i++)
		{
			int s,e;
			cin>>s>>e;
			entry[i]=s;
			exit[i]=e;
			points[s];
			points[e];
		}
		
		int rank=1;
		for(map<int,int>::iterator i = points.begin();i!=points.end();i++)
			i->second=rank++;
		
		for(int i=0;i<n;i++){
			present[points[entry[i]]]++;
			present[points[exit[i]]]--;
		}
		int maximum=0;
		for(int i=1;i<500;i++){
			present[i]+=present[i-1];
			maximum=max(maximum,present[i]);
		}
		cout<<maximum<<endl;
	}
}
