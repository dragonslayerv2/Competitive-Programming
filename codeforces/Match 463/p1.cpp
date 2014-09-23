#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int s;
	cin>>s;
	
	pair<int,int> money= make_pair(s,0);
	int currentMax = -1;
	for(int i=0;i<n;i++){
		pair<int,int> currentCost;
		cin>>currentCost.first>>currentCost.second;
		for(int j=1;j==1;j++){
			pair<int,int> newCost = make_pair(currentCost.first*j+(currentCost.second*j)/100,(currentCost.second*j)%100);
			if(newCost<=money){
				currentMax= max(currentMax,((100-newCost.second!=100)?100-newCost.second:0));
			}
		}
	}
	cout<<currentMax;
}
