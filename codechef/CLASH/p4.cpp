#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define IMPOSSIBLE "IMPOSSIBLE"
#define POSSIBLE "POSSIBLE"

vector<int> a;

map<int,bool> values;
bool isPossible(int x){
	if(x==1)
		return true;
	if(values.find(x)==values.end()){
		bool ans = false;
		for(int i=0;i<a.size();i++)
			if(x%a[i]==0)
				ans=(ans||isPossible(x/a[i]));
		values[x]=ans;
	}
	return values[x];
}
int main(){
	int n;
	cin>>n;
	int x,y;
	cin>>x>>y;
	
	a.reserve(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x!=1)
			a.push_back(x);
	}
		
	if(y%x)
		cout<<IMPOSSIBLE<<endl;
	else
		cout<<(isPossible(y/x)?POSSIBLE:IMPOSSIBLE)<<endl;
}
