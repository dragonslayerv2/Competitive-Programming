#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool I=false;
		bool Y=false;
		while(n--){
			char x;
			cin>>x;
			if(x=='I')
				I=true;
			if(x=='Y')
				Y=true;
		}		
		if(I&&Y)
			cout<<"NOT SURE";
		else if(I)
			cout<<"INDIAN";
		else if(Y)
			cout<<"NOT INDIAN";
		else
			cout<<"NOT SURE";
		cout<<endl;
	}
}
