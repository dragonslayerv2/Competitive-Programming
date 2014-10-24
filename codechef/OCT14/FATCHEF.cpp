#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MOD 1000000009
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<pair<int,char> > colors(m);
		for(int i=0;i<m;i++)
			cin>>colors[i].second>>colors[i].first;
		sort(colors.begin(),colors.end());
		
		long long ans=1;
		for(int i=1;i<colors.size();i++){
			if(colors[i-1].second!=colors[i].second){
				ans*=(colors[i].first-colors[i-1].first);
				ans%=MOD;
			}
		}
		
		cout<<ans<<endl;
	}
}
