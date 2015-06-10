#include<iostream>
#include<vector>
using namespace std;

class NumberGameAgain{
	public:
		
		bool isReducible(long long a, long long b){
			while(b){
				if(a==b)
					return true;
				b>>=1;
			}
			return false;
		}
		long long solve(int k, vector<long long> table){
			vector<bool> isValid(table.size(),true);
			for(int i=0;i<table.size();i++){
				for(int j=i+1;j<table.size();j++){
					if(isReducible(table[i],table[j]))
						isValid[j]=false;
					else if(isReducible(table[j],table[i]))
						isValid[i]=false;
				}
			}

			long long sum=0;
			for(int i=0;i<table.size();i++){
				if(isValid[i]){
					int l=0;
					while(table[i])
					{
						l++;
						table[i]>>=1;
					}
					
					sum+= ((((long long)1)<<(k-l+1))-1);
				}
			}
			return ((((long long)1)<<(k))-2)-sum;
		}
};

int main(){
	vector<long long> table ={2,4,6};
	cout<<NumberGameAgain().solve(3,table);
}
