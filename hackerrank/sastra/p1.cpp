#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	
	char values[]={'0','P','Q','q','p'};
	while(t--){
		int n;
		cin>>n;
		stack<char> ans;
		while(n){
			int rem=n%5;
			switch(rem){
				case 0:
				case 1:
				case 2: 
						ans.push(values[rem]);
						n/=5;
						break;
				case 3:
				case 4:
						ans.push(values[rem]);
						n/=5;
						n++;
						break;
			}
			
		}
		while(!ans.empty()){
			cout<<ans.top();
			ans.pop();
		}
		cout<<endl;
	}
}
