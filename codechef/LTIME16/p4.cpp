#include<iostream>
#include<vector>
using namespace std;

struct query{
	int type;
	int l,r;
};
int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.txt","r",stdin);
	#endif
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		int q;
		cin>>q;
		vector<query> queries(q);
		bool is2=false;
		for(int i=0;i<q;i++){
			cin>>queries[i].type>>queries[i].l>>queries[i].r;
			queries[i].l--;
			queries[i].r--;
			is2=(is2||(queries[i].type==2));
		}
		
		if(is2){
			vector<int> temp;
			temp.reserve(n);
			for(int i=0;i<queries.size();i++){
				if(queries[i].type==1){
					int count=1;
					for(int j=queries[i].l+1;j<=queries[i].r;j++)
					{
						count+=(a[j]!=a[j-1]);	
					}
					cout<<count<<endl;
				}
				else{
					temp.clear();
					for(int j=queries[i].l;j<=queries[i].r;j++)
						temp.push_back(a[j]);
					for(int j=0;j<a.size();j++)
						if(j<queries[i].l||j>queries[i].r)
							temp.push_back(a[j]);	
					a.swap(temp);
				}
			}
		}
		else
		{
			vector<int> prefixSum(n);
			for(int i=1;i<n;i++){
				prefixSum[i]=prefixSum[i-1];
				if(a[i]!=a[i-1])
					prefixSum[i]++;
			}
			
			for(int i=0;i<queries.size();i++)
				cout<<prefixSum[queries[i].r]-prefixSum[queries[i].l]+1<<endl;
		}
	}
}
