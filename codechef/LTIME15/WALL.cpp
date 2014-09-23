#include<iostream>
#include<map>
#include<vector>
#include<assert.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		unsigned long long h;
		cin>>h;
		unsigned long long n,m;
		cin>>n>>m;
		unsigned long long a,b,ind;
		cin>>a>>b>>ind;
		
		vector<unsigned long long> d(m);
		for(int i=0;i<m;i++)
			cin>>d[i];
		
		vector<unsigned long long> index;
		
		map<unsigned long long,unsigned long long> indexPosition;
		
		index.push_back(ind);
		indexPosition[ind]=index.size()-1;
		
		long long loopAt=-1;
		for(int i=0;i<m+100;i++){
			ind=(a*ind+b)%m;
			if(indexPosition.find(ind)==indexPosition.end()){
				index.push_back(ind);
				indexPosition[ind]=index.size()-1;
			}
			else{
				loopAt = indexPosition[ind];
				break;
			}
		}
		assert(loopAt!=-1);
		
		unsigned long long x=0;
		n--;
		
		for(int i=0;i<loopAt;i++){
			if(n<=0)
				break;
			x+=d[index[i]];
			n--;
		}
		
		unsigned long long loopSum=0;
		for(int i=loopAt;i<index.size();i++){
			loopSum+=d[index[i]];
		}
		
		unsigned long long loopSize = (index.size()-loopAt);
		
		x+=loopSum*((n)/loopSize);
		n%=loopSize;
		
		unsigned long long i=loopAt;
		while(n--){
			x+=d[index[i]];	
			i++;
		}
		cout<<(h*x)/2;
		cout<<((h*x)%2?".5":".0");
		cout<<endl;
	}
}
