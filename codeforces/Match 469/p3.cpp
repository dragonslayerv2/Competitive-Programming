#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
	
//	freopen("test.txt","r",stdin);
	int n,a,b;
	cin>>n>>a>>b;
	vector<int> elements(n);
	
	set<int> A;
	set<int> B;
	map<int,int> place;
	for(int i=0;i<n;i++){
		cin>>elements[i];
		place[elements[i]]=-1;
	}
	
	bool isPossible=true;	
	for(int i=0;i<n;i++){
		if(place[elements[i]]==-1){
			bool aExist=(place.find(a-elements[i])!=place.end());
			bool bExist=(place.find(b-elements[i])!=place.end());
			if(aExist&&bExist){	}
			else if(aExist)
			{
				if(B.find(a-elements[i])!=B.end()){
					isPossible=false;
					break;
				}
				else{
					int current=elements[i];
					while(place.find(current)!=place.end()&&place[current]==-1){
						place[current]=0;
						A.insert(current);
						current=a-current;
						
					}
					if(place.find(current)==place.end()||place[current]!=0)
						isPossible=false;
				}
			}
			else if(bExist){
				if(A.find(b-elements[i])!=A.end()){
					isPossible=false;
					break;
				}
				else{
					int current=elements[i];
					while(place.find(current)!=place.end()&&place[current]==-1){
						place[current]=1;
						B.insert(current);
						current=b-current;
					}
					if(place.find(current)==place.end()||place[current]!=1)
						isPossible=false;
				}
			}
			else{
				isPossible = false;
				break;
			}
		}
	}
	if(isPossible){
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			if(A.find(elements[i])!=A.end())
				cout<<"0";
			else
				cout<<"1";
			cout<<" ";
		}
	}
	else
		cout<<"NO";
}
