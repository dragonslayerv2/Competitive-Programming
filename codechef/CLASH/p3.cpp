#include<iostream>
#include<map>
using namespace std;

int main(){
	int n;
	cin>>n;
	map<string,int> personLevel;
	map<int,string> levelPerson;
	while(n--){
		string person;
		cin>>person;
		int &level = personLevel[person];
		level++;
		if(levelPerson[level].size()==0)
			levelPerson[level]=person;	
	}
	
	for(map<int,string>::const_iterator i=levelPerson.begin();i!=levelPerson.end();i++)
		cout<<i->first<<" "<<i->second<<endl;
}
