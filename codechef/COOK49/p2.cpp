#include<iostream>
#include<vector>
using namespace std;


int main(){
//	freopen("test2.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> finalArray(n);
		for(int i=0;i<n;i++)
			cin>>finalArray[i];
		vector<int> incrementArray(2*n);
		while(m--){
			int a,b;
			cin>>a>>b;
			incrementArray[a*2-2]++;
			incrementArray[b*2-1]--;
		}
		int lastIncrement = 0;
		for(int i=0;i<incrementArray.size();i++){
			lastIncrement+=incrementArray[i];
			incrementArray[i]=lastIncrement;
		}
		
		int setNumber = 1;
		int currentPosition = 0;
		while(currentPosition<incrementArray.size()){
		
			if(incrementArray[currentPosition]>0)
				incrementArray[currentPosition]=setNumber;
			else
				setNumber++;
			currentPosition++;
		}
		bool flag = true;
		for(int i=0;i<finalArray.size();i++)
		{
			int finalArrayElementPosition = 2*finalArray[i]-2;
			int oldArrayElementPosition = 2*(i+1)-2;
			if(incrementArray[finalArrayElementPosition]!=incrementArray[oldArrayElementPosition]){
				flag=false;
				break;
			}
				
		}
		if(flag)
			cout<<"Possible";
		else
			cout<<"Impossible";
		cout<<endl;
	}
}

