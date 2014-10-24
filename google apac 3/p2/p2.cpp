#include<iostream>
#include<climits>
#include<vector>
using namespace std;

#define INVALID INT_MAX
int main(){
	freopen("smallin.in","r",stdin);
	freopen("outsmall.txt","w",stdout);
	
	vector<int> digits(1000001);
	vector<int> digitsCount(1000001);
	for(int i=1;i<=1000000;i++){
		int iCopy=i;
		int currentHash=0;
		while(iCopy){
			digitsCount[i]++;
			currentHash|=(1<<(iCopy%10));
			iCopy/=10;
		}
		digits[i]=currentHash;
	}
	
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		cout<<"Case #"<<t+1<<": ";
		int presentDigits=0;
		for(int i=0;i<10;i++)
		{
			int x;
			cin>>x;
			if(x)
				presentDigits|=(1<<i);
		}
		int n;
		cin>>n;

		vector<int> clicks(n+1,INVALID);
		vector<char> lastMove(n+1);
		for(int i=1;i<=n;i++)
			if(!((digits[i])&(~presentDigits))){
				clicks[i]=digitsCount[i];
				lastMove[i]='d';
			}
				
				
		
		for(int i=1;i<=n;i++){
			if(clicks[i]!=INVALID){
				for(int j=2;j<=n/i;j++){
					if(!((digits[j])&(~presentDigits))){
						if(clicks[i*j]>clicks[i]+digitsCount[j]+1){
							clicks[i*j]=min(clicks[i*j],clicks[i]+digitsCount[j]+1);	
							lastMove[i*j]='m';
						}
					}
				}
			}
		}
		if(clicks[n]==INVALID)
			cout<<"Impossible";
		else if(!((digits[n])&(~presentDigits)))
			cout<<digitsCount[n]+1;
		else
			cout<<clicks[n]+1;
		cout<<endl;
	}
}
