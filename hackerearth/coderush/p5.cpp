#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000007LL
int main(){
	vector<long long> ans(1000000+1);
	ans[1]=2;
	ans[2]=3;
	for(int i = 3;i<ans.size();i++)
	{
		ans[i]=ans[i-1]+ans[i-2];
		ans[i]%=MOD;
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<ans[n]<<endl;
	}
}
