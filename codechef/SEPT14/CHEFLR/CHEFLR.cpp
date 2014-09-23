#include<iostream>
using namespace std;

#define MOD 1000000007

char s[100005];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.txt","r",stdin);
	#endif
		
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		int currentLevel = 1;
		long long currentNumber = 1;
		for(int i=0;s[i];i++)
		{
			currentNumber*=2;
			currentLevel++;
			if(s[i]=='l'){
				if(currentLevel&1)
					currentNumber--;
			}
			else
			{
				currentNumber++;
				if(!(currentLevel&1))
					currentNumber++;
			}
			currentNumber%=MOD;
		}
		cout<<currentNumber<<endl;
	}
	
}
