#include<iostream>
#include<map>
#include<limits>
#include<vector>
#include<assert.h>
#include<climits>
using namespace std;

int main(){
	long long n,k;
	cin>>n>>k;
	vector<long long> a(n);
	for(long long i=0;i<n;i++)
		cin>>a[i];
		
	pair<long long,long long> ans=make_pair(numeric_limits<long long>::max(),numeric_limits<long long>::max());	
	
	if(n>50){
		long long maxDif = 0;
		long long D = 0;
		map<long long,long long> dFrequencies;
		for(long long i=0;i<n-1;i++){
			long long currentFrequency = (++dFrequencies[a[i+1]-a[i]]);
			if(maxDif<currentFrequency){
				maxDif=currentFrequency;
				D=a[i+1]-a[i];
			}
		}
		
		for(int i=n-1;i>=n-1-13;i--){
			long long A=a[i]-i*D;
			
			long long changedCount = 0;
			for(long long l=0;l<n;l++)					
				if(a[l]!=A+l*D)
					changedCount++;	
			if(changedCount<=k)
				ans=min(ans,make_pair(A,D));
		}
	}
	else{
		
		for(long long i=0;i<n;i++)
			for(long long j=i+1;j<n;j++)
				if(((a[j]-a[i])%(j-i))==0)
				{
					long long D=(a[j]-a[i])/(j-i);
					long long A=a[i]-i*D;
					
					long long changedCount = 0;
					for(long long l=0;l<n;l++)					
						if(a[l]!=A+l*D)
							changedCount++;	
					if(changedCount<=k)
					{
						ans=min(ans,make_pair(A,D));
					}
				}	
		
		
	}
	for(long long i=0;i<n;i++)
			cout<<ans.first+ans.second*i<<" ";
}
