#include<iostream>
using namespace std;

string s;
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		int first,last;
		first = 0;
		last = s.size()-1;
		while(last>=first){
			if(s[last]!=s[first])
				break;
			last--;
			first++;
		}
		if(last<first)
			cout<<1;
		else
			cout<<2;
		cout<<endl;
	}
}
