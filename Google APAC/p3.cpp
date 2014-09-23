#include<iostream>
#include<map>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;


typedef map<string,list<pair<int,string> > > graph;

string getString(char delimiter){
	char c;
	string ans;
	while((c=getchar())!=delimiter){
		ans.push_back(c);
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout<<"Case #"<<T<<":"<<endl;
		
		graph G;
		int n;
		cin>>n;
		while(n--){
			string var1=getString('+');
			string var2=getString('=');
			int value;
			cin>>value;	
			
			G[var1].push_back(make_pair(var2,value));	
			G[var2].push_back(make_pair(var1,value));	
		}
		
	}
}
