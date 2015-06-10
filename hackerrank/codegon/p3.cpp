#include<iostream>
#include<cmath>
using namespace std;

string n;

bool isCalculated[20][10][500]={false};
long long cost[20][10][500];

long long solve(int pos,int threeMod,long long c){
	if(pos==n.size()){
		if(threeMod==0&&c>=0)
			return 1;
		else
			return 0;
	}
	if(c<0)
		return 0;
	if(!isCalculated[pos][threeMod][c]){
		int currentDigit=n[pos]-'0';
		int newDigit;
		if(pos==0)
			newDigit=1;
		else 
			newDigit=0;
		cost[pos][threeMod][c]=0;
		for(;newDigit<=9;newDigit++)
			cost[pos][threeMod][c]+=solve(pos+1,(threeMod*10+newDigit)%3,c-abs(newDigit-currentDigit));
		isCalculated[pos][threeMod][c]=true;
	}
	return cost[pos][threeMod][c];
}
int main(){
	
	int c;
	cin>>n>>c;
	cout<<solve(0,0,c);
}
