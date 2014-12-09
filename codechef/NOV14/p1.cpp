#include<iostream>
#include<vector>
using namespace std;

char s[100005];
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		set<int> distinct;
		for(int i=0;s[i];i++)
			distinct.insert(s[i]);
		cout<<distinct.size();
	}
}
