#include<bits/stdc++.h>
#define BLACK 0
#define WHITE 1
using namespace std;
int main(){
	int t;
	cin>>t;
	int currentColor=BLACK;
	while(t--){
		string type;
		cin>>type;
		if(type=="Qi"){
			if(currentColor==BLACK)
				currentColor=WHITE;
			else
				currentColor=BLACK;
		}
		else if(type=="Qb"){ 
			int x,y;
			cin>>x>>y;
			vector<int> storeX;
			vector<int> storeY;
			while(x!=0){
				storeX.push_back(x%2);
				x=x/2;
			}
			while(y!=0){
				storeY.push_back(y%2);
				y=y/2;
			}
			int counter=0;
			int ptrX=storeX.size()-1;
			int ptrY=storeY.size()-1;
			while(ptrX>=0 && ptrY>=0){
				if(storeX[ptrX]!=storeY[ptrY])
					break;
				ptrX--;
				ptrY--;
				counter++;
			}
			int ans=0;
			int minLimit = min(storeX.size(),storeY.size());
			int maxLimit = max(storeX.size(),storeY.size());
			for(int i=counter;i<=minLimit;i++){
				int current=i%2;
				if(currentColor ^ current)
				{
					if(i==counter)
						ans++;
					else
						ans+=2;
				}
			}
			for(int i=minLimit+1;i<=maxLimit;i++){
				int current=i%2;
				if(currentColor ^ current)
					ans++;
			}		
			cout<<ans<<"\n";
		}
		else if(type=="Qr"){
			int x,y;
			cin>>x>>y;
			vector<int> storeX;
			vector<int> storeY;
			while(x!=0){
				storeX.push_back(x%2);
				x=x/2;
			}
			while(y!=0){
				storeY.push_back(y%2);
				y=y/2;
			}
			int counter=0;
			int ptrX=storeX.size()-1;
			int ptrY=storeY.size()-1;
			while(ptrX>=0 && ptrY>=0){
				if(storeX[ptrX]!=storeY[ptrY])
					break;
				ptrX--;
				ptrY--;
				counter++;
			}
			int ans=0;
			int minLimit = min(storeX.size(),storeY.size());
			int maxLimit = max(storeX.size(),storeY.size());
			for(int i=counter;i<=minLimit;i++){
				int current=i%2;
				if(!(currentColor ^ current))
				{
					if(i==counter)
						ans++;
					else
						ans+=2;
				}
			}
			for(int i=minLimit+1;i<=maxLimit;i++){
				int current=i%2;
				if(!(currentColor ^ current))
					ans++;
			}		
			cout<<ans<<"\n";
		}
	}
}
