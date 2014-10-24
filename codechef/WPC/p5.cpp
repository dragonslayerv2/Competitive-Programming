#include<bits/stdc++.h>
using namespace std;

int main()
 {
 	int t;
 	cin>>t;
 	while(t--){
 		
 	
 	int n,i,ans,x;
 	cin>>n;
 	 ans=0;
 	for(i=0;i<n;i++)
 	 {
 	 	cin>>x;
 	 	ans=max(x,ans);
 	 }
 	
 	cout<<ans<<endl;
 	}
 }
