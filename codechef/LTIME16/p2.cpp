#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	vector<int> a;
	vector<int> primeCount;
	while(t--){
		int n;
		cin>>n;
		a.resize(n);
		primeCount.resize(1000000);
		
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			int factorCount=0;
			while((x&1)==0){
				x>>=1;
				factorCount++;
			}
			primeCount[2]=max(primeCount[2],factorCount);
			for(int j=3;j*j<=x;j+=2){
				factorCount=0;
				while((x%j)==0){
					x/=j;
					factorCount++;
				}
				primeCount[j]=max(primeCount[j],factorCount);
			}
			if(x!=1)
				primeCount[x]=max(primeCount[x],1);
		}
		int ans=0;
		for(int i=0;i<primeCount.size();i++)
			ans+=primeCount[i];
		cout<<ans<<endl;
		a.clear();
		primeCount.clear();
	}

}
