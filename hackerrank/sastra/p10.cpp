#include<iostream>
#include<vector>
using namespace std;


int main(){
	int t,k;
	cin>>t>>k;
	vector<long long> possible(100);
	possible[0]=1;
	for(int i=0;i<possible.size();i++){
		if(i<k)
			possible[i]=(1<<i);
		else{
			for(int j=i-1;j>=i-k&&j>=0;j--)
				possible[i]+=possible[j];
		}
		if(possible[i]>1000000000000000LL){
			possible.resize(i+1);
			break;
		}	
	}
	while(t--){
		long long n;
		cin>>n;
		int digit=0;
		while(possible[digit]<=n)
			digit++;
		while(digit>0){
			if(n>=possible[digit-1]){
				cout<<1;
				n-=possible[digit-1];
			}
			else
				cout<<0;
			digit--;
		}
		cout<<endl;
	}	
}
