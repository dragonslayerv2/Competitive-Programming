#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> sequences;

void generate(int lCount,int rCount,int n,string s){
	if(lCount<rCount)
		return;
	if(lCount>n||rCount>n)
		return;
	
	if(lCount==n&&rCount==n){
		sequences.push_back(s);
	}
	generate(lCount+1,rCount,n,s+'(');
	generate(lCount,rCount+1,n,s+')');
}
int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cout<<"Case #"<<t<<": ";
		long long n,k;
		cin>>n>>k;
		sequences.clear();
		generate(0,0,n,"");
		sort(sequences.begin(),sequences.end());
		if(k>sequences.size())
			cout<<"Doesn't Exist!";
		else
			cout<<sequences[k-1];
		cout<<endl;
	}
}
