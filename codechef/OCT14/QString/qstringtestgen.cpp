#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(type==0){
			int l,r,rank;
			cin>>l>>r>>rank;
			vector<int> x;
			for(int i=l;i<=r;i++)
				x.push_back(a[i]);
			sort(x.begin(),x.end());
			cout<<x[rank-1]<<endl;
		}
		else{
			int l,r,value;
			cin>>l>>r>>value;
			int count=0;
			for(int i=l;i<=r;i++)
				if(a[i]<value)
					count++;
			cout<<count<<endl;
		}
	}
}
