#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000007

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>k>>n;
		vector<long long> arr(n+1,1);
		arr[1]=1;
		arr[2]=k;
		for(int i=3;i<=n;i++){
			for(int j=1;j<i;j++){
				arr[i]*=arr[j];
				arr[i]%=MOD;
			}
		}
		cout<<arr[n]<<endl;
	}
}
