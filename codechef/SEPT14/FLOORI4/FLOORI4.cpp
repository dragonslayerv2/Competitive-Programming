#include<iostream>
using namespace std;

inline long long iterativePower(long long a, int power, long long MOD){
	long long ans=1;
	while(power--){
		ans*=a;
		ans%=MOD;
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
		
		long long iterations = sqrt(n);
		
		long long solution = 0;
		long long last = n;

		for(long long i = 2;i<=iterations;i++)
		{
			long long first = n/i+1;
			solution+ = (i-1)*(sum(last)-sum(first-1));
			solution%=m;
			last = first-1;
		}
		
		for(long long i=1;i<=iterations;i++){
			solution+=iterativePower(i,4,m)*(n/i);
			solution%=m;
		}
		
		for(long long i = iterations+1;i<=last;i++){
			solution+=iterativePower(i,4,m)*(n/i);
			solution%=m;
		}
	}
}
