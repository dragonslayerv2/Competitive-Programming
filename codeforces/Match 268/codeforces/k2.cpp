#include<bits/stdc++.h>
using namespace std;
int main()
 {
 	long long n,k,i;
 	cin>>n>>k;
  char s[100005];
 	cin>>s;
 	map<char,long long> mp;
 	for(i=0;i<n;i++)
 	  mp[s[i]]++;
 	  vector<long long> v;
 	for(map<char,long long>::iterator it=mp.begin();it!=mp.end();it++)
 	  v.push_back(it->second);
 	sort(v.rbegin(),v.rend());
 	long long ans=0;
 	long long count=0;
 	for(i=0;i<v.size() && count<k;i++)
 	  {if(count+v[i]<=k)
 	     {count+=v[i];
 	      ans+=v[i]*v[i];
 	     }
 	    else 
 	      {ans+=(k-count)*(k-count);
 	       count=k;
 	      }
 	     // cout<<v[i]<<" ";
 	  }
 	  cout<<ans<<endl;
 	
 }
