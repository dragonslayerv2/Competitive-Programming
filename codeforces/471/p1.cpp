#include<iostream>
#include<map>
using namespace std;

int main(){
	map<int,int> stickCount;	
	
	bool isFour=false;
	for(int i=0;i<6;i++){
		int stick;
		cin>>stick;
		stickCount[stick]++;
		if(stickCount[stick]==4)
			isFour=true;
	}
	if(isFour){
		int count=stickCount.size();
		for(map<int,int>::iterator i=stickCount.begin();i!=stickCount.end();i++)
			if(i->second==4)
				count--;
		if(count==0||count==1)
			cout<<"Elephant";
		else
			cout<<"Bear";
	}
	else
		cout<<"Alien";
}
