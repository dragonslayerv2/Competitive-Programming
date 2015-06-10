#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<map>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	map<string,int> stringCounts;
	long long counts=0;
	while(n--){
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++)
			s[i]=tolower(s[i]);
		counts+=stringCounts[s];
		reverse(s.begin(),s.end());
		stringCounts[s]++;
	}
	cout<<counts;
}
