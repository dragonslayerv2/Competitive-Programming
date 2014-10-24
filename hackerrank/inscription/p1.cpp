#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> freq(1001);
	
	int maxPosition=0;
	while(n--){
		int x;
		cin>>x;
		freq[x]++;
		if(freq[x]>maxPosition)
			maxPosition=x;
	}
	
	bool moreAvailable=false;
	for(int i=0;i<freq.size();i++)
		if(maxPosition!=i&&freq[maxPosition]==freq[i])
			moreAvailable=true;
			
	if(moreAvailable)
		cout<<-1;
	else
		cout<<maxPosition;
}
