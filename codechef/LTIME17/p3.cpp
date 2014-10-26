#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		map<int,int> freq;
		int n,f;
		cin>>n>>f;
		while(n--){
			int x;
			cin>>x;
			freq[x]++;
		}
		long long count=0;
		for(map<int,int>::iterator j=freq.begin();j!=freq.end();j++){
			count+=(j->second*(j->second-1))/2;
			int h=j->first;
			while(h){
				if(h%f)
					break;
				h/=f;
				map<int,int>::iterator i=freq.find(h);
				if(i!=freq.end())
					count+=j->second*i->second;
			}
		}
		cout<<count<<endl;
	}
}
