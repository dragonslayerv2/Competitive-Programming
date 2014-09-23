#include<bits/stdc++.h>
using namespace std;

int main()
 {
 	
 	long long sum=0,ans=0, n,i;
 	cin>>n;
 	vector<long long > a(n);
 	for(i=0;i<n;i++)
 	  {
 	  cin>>a[i];
 	  sum+=a[i];
 	}
 	ans=sum;
 	sort(a.begin(),a.end());
 	for(i=0;i<n-1;i++)
 	  {ans+=sum;
 	   sum-=a[i];
 	  }
 	cout<<ans<<endl;
 	
 	
 }
