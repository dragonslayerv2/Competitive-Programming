#include<iostream>
using namespace std;

#define MOD 1000000007LL

long long dp[300000][500];


int R,G;
	
inline int isPossible(int r,int h){
	int g=R+G-((h*(h+1))/2)-r;
	return (r>=0&&g>=0&&r<=R&&g<=G);
}
int main(){
	cin>>R>>G;

	for(int r=0;r<300000;r++)
		if(isPossible(r,0))
			dp[r][0]=1;
			
	long long ansWays=0;
	for(int h=1;1;h++){
		bool yes=false;
		long long newWays=0;
		
		for(int r=0;r<=R;r++){
			if(isPossible(r,h)){
				yes=true;
				if(isPossible(r+h,h-1))
					dp[r][h]+=dp[r+h][h-1];
				if(isPossible(r,h-1))
					dp[r][h]+=dp[r][h-1];
				dp[r][h]%=MOD;
				newWays+=dp[r][h];
				newWays%=MOD;
			}	
		}
		
		if(yes)
			ansWays=newWays;			
		else
			break;
	}
	
	cout<<ansWays;
}
