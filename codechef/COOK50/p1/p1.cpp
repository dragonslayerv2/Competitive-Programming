#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

inline int gcd(int a, int b)
{
   int temp;    
   while(b)
   {
           temp=a;
           a=b;
           b=temp%b;
   }
   return a;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a;
		cin>>a;
		for(int i=1;i<n;i++){
			int x;
			cin>>x;
			a=gcd(a,x);
		}
		if(a==1)
			cout<<n;
		else
			cout<<-1;
		cout<<endl;
		
			
	}
	
}
