#include<iostream>
#include<map>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	map<pair<int,int>, pair<int,int> > object;
	
	while(n--){
		int attr,id,value,pr;
		cin>>attr>>id>>value>>pr;
		pair<int,int> key=make_pair(attr,id);
		
		pair<int,int> lastValue=object[key];
		pair<int,int> newValue=make_pair(value,pr);
		if(lastValue.second<=newValue.second)
			object[key]=newValue;
	}
	while(m--){
		int attr,id;
		cin>>attr>>id;
		pair<int,int> value=object[make_pair(attr,id)];
		cout<<value.first<<endl;
	}
}
