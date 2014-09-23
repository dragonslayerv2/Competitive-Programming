#include<iostream>
using namespace std;

int main()
 {int n,i,j;
 	cin>>n;
 	char s[n+1][n+2];
 	for(i=0;i<n;i++)
 	 cin>>s[i];
 	 int flag=1;
 	for(i=0;i<n;i++)
 	  for(j=0;j<n;j++)
 	   { int count =0;
 	    if(i!=0 && s[i-1][j]=='o')
 	      count++;
 	    if(j!=0 && s[i][j-1]=='o')
 	      count++;
 	    if(i!=n-1 && s[i+1][j]=='o')
 	      count++;
 	    if(j!=n-1 && s[i][j+1]=='o')
 	      count++;
 	    if(count%2)
 	      flag=0;
 	    
 	   }
 	if(flag)
 	 cout<<"YES"<<endl;
 	 else
 	  cout<<"NO"<<endl;
 }
