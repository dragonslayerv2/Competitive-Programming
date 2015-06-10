#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	string firstWord;
	string secondWord;
	cin>>firstWord>>secondWord;
	
	bool isPossible[26][26][26];
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			for(int k=0;k<26;k++)
				isPossible[i][j][k]=true;
	int n;
	cin>>n;
	while(n--){
		string a,b,c;
		cin>>a>>b>>c;
		for(int i=0;i<a.size();i++)
			
	}
	
}
