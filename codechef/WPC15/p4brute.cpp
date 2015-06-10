#include<iostream>
#include<vector>
using namespace std;

int solve(int len,int k,int pos,vector<int> &arr){
	if(pos==len){
		for(int i=0;i<len;i++)
		{
			for(int j=i+1;j<len;j++){
				int left=i;
				int right=j;
				while(left<=right){
					if(arr[left]!=arr[right])
						break;
					left++;
					right--;
				}
				if(right<left)
					return 0;
			}
		}
		return 1;
	}
	else{
		int ans=0;
		for(int currentNumber=0;currentNumber<k;currentNumber++){
			arr[pos]=currentNumber;
			ans+=solve(len,k,pos+1,arr);
		}
		return ans;
	}
}
int main(){
	for(int i=1;i<8;i++){
		for(int k=1;k<8;k++){
			vector<int> arr(i);
			cout<<solve(i,k,0,arr)<<" ";			
		}
		cout<<endl;
	}
}
