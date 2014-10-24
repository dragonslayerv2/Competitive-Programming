#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

#define convertToPosition(firstPos, secondPos) ((secondPos)-(firstPos)+102)
#define convertBack(firstPos,secondPos) ((secondPos)+(firstPos)-102)

#define INVALID 10000
char s[100005],w[100005];
#include<stdio.h>

vector<vector<int> > dp(100005,vector<int>(205));
int main(){
	
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	scanf("%d",&t);
	while(t--){
	//	cout<<"------------";
		scanf("%s %s",s,w);
		int k;
		int a,b;
		scanf("%d %d %d",&a,&b,&k);
		int sLen=strlen(s),wLen=strlen(w);
		
		if(a==0)
			cout<<0;
		else if(b==0)
			cout<<abs(sLen-wLen)*a;
		else{
			for(int i=0;i<sLen+1;i++)
				for(int j=0;j<205;j++)
					dp[i][j]=INVALID;
			for(int j=0;j<205;j++){
				int wPos=convertBack(sLen,j);
			//	cout<<"Working for "<<wPos<<"got j "<<j<<endl;
				if(wPos<=wLen)
					dp[sLen][j]=(wLen-wPos)*a;
			}
			
			for(int sPos=sLen-1;sPos>=0;sPos--){
				bool allInvalid=true;
				for(int j=204;j>=0;j--){

					dp[sPos][j]=INVALID;
					
					int wPos=convertBack(sPos,j);
					
				//	cout<<"checking for "<<sPos<<" "<<wPos<<endl;
					if(wPos<0||wPos>wLen){
						dp[sPos][j]=INVALID;
					}
						
					else if(wPos==wLen)
					{
						dp[sPos][j]=(sLen-sPos)*a;
						if(dp[sPos][j]>k)
							dp[sPos][j]=INVALID;
					}
					else if(s[sPos]==w[wPos]){
						dp[sPos][j]=dp[sPos+1][convertToPosition(sPos+1,wPos+1)];
					}
						
					else{
						int insert,del,replace;
						
						insert=del=replace=INVALID;
						
						int insertNewPosition=convertToPosition(sPos+1,wPos);
						if(insertNewPosition>=0&&insertNewPosition<205)
							insert=dp[sPos+1][insertNewPosition]+a;

						int delNewPosition=convertToPosition(sPos,wPos+1);
						if(delNewPosition>=0&&delNewPosition<205)
							del=dp[sPos][delNewPosition]+a;
						
						int replaceNewPosition=convertToPosition(sPos+1,wPos+1);
						if(replaceNewPosition>=0&&replaceNewPosition<205)
							replace=dp[sPos+1][replaceNewPosition]+b;
						
						dp[sPos][j]=min(insert,min(del,replace));
						if(dp[sPos][j]>k)
							dp[sPos][j]=INVALID;
					}	
					if(dp[sPos][j]<INVALID)
					allInvalid=false;
				}
				if(allInvalid)
					break;
			}
			cout<<(dp[0][convertToPosition(0,0)]>=INVALID?-1:dp[0][convertToPosition(0,0)]);
		}
		cout<<endl;
	}		
}
