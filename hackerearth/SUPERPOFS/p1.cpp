#include<iostream>
#include<ctype.h>
#include<cstring>
#include<vector>
using namespace std;

int main(){
	vector<char> hash(26);
	int n;
	cin>>n;
	for(int i=0;i<hash.size();i++)
		hash[i]='a'+i;
	
	while(n--){
		char a,b;
		cin>>a>>b;
		a=tolower(a);
		b=tolower(b);
		for(int i=0;i<hash.size();i++){
			if(hash[i]==a)
				hash[i]=b;
			else if(hash[i]==b)
				hash[i]=a;
		}
	}
	
	string s;
	while(cin>>s){
		for(int i=0;i<s.size();i++){
			if(s[i]==' ')
				cout<<' ';
			else{
				int pos=tolower(s[i])-'a';
				
				if(isupper(s[i]))
					cout<<(char)toupper(hash[pos]);
				else
					cout<<(char)tolower(hash[pos]);	
			}
			
		}
	}
}
