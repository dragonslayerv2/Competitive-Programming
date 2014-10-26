#include<iostream>
#include<map>
using namespace std;

#define MOD 1000000009
map<long long,long long> dp;
long long f(long long n,long long K){
	if(n==0)
		return 1;
	else
	{
		map<long long,long long>::iterator i=dp.find(n);
		if(i==dp.end())
		{
			long long ans=0;
			if(K==3){
				for(int i=0;i<2;i++){
					for(int j=0;j<2;j++)
						for(int k=0;k<2;k++)
						{
							if((i&j)==j&&((j&k)==k))
							{
								int sum=i+j+k;
								if(sum<=n&&((sum&1)==(n&1)))
									ans+=f((n-sum)>>1,K);
							}
							ans%=MOD;
						}						
				}
			}
			else{
				for(int i=0;i<2;i++){
					for(int j=0;j<2;j++)
						for(int k=0;k<2;k++)
							for(int l=0;l<2;l++)
							{
								if((i&j)==j&&((j&k)==k)&&(k&l)==l)
								{
									int sum=i+j+k+l;
									if(sum<=n&&((sum&1)==(n&1)))
										ans+=f((n-sum)>>1,K);
								}
								ans%=MOD;
							}
				}				
			}
			dp[n]=ans;
			return ans;
		}
		else
			return i->second;		
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		dp.clear();
		long long k,n;
		cin>>k>>n;
		cout<<f(n,k)<<endl;
	}
}
