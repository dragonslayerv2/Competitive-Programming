#include<iostream>
#include<cstring>
#include<map>
#include<cmath>
using namespace std;

vector<vector<int> > dp;
char s[100005],w[100005];
int sLen,wLen,a,b;
#define INVALID 100000000
int getMin(int sPos,int wPos){
	if(k<0)
		return INVALID;
	else if(sPos==sLen&&wPos==wLen)
		return 0;
	else if(sPos==sLen|| wPos==wLen)
		return abs(wPos-sPos)*a;
	else if(abs(sPos-wPos)>k)
		return INVALID;
	else{
		
		if(it==dp.end())
		{
			int ans;
			if(s[sPos]==w[wPos])
				ans=getMin(sPos+1,wPos+1,k);
			else{
				int insert=a+getMin(sPos+1,wPos,k-a);
				int del=a+getMin(sPos,wPos+1,k-a);
				int replace=b+getMin(sPos+1,wPos+1,k-b);
				ans=min(insert,del);
				ans=min(ans,replace);
			}
		//	cout<<"Ans for "<<s+sPos<<" "<<w+wPos<<" is "<<ans<<endl;
			dp[key]=ans;
			return ans;
		} 
		return it->second;
	}	
}
#include<cstdio>
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	
	while(t--){
	//	cout<<"------------";
		cin>>s>>w;
		int k;
		cin>>a>>b>>k;
		sLen=strlen(s),wLen=strlen(w);
		
		if(a==0)
			cout<<0;
		else if(b==0)
			cout<<abs(sLen-wLen)*a;
		else{
			dp.clear();
			int ans=getMin(0,0,k);
			if(ans>=INVALID)
				ans=-1;
			cout<<ans;
		}
		cout<<endl;
	}
}
