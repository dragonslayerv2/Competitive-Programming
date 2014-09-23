#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	getchar();
	while(t--){
		char E[10005];
		cin.getline(E,sizeof(E));
		map<char,int> frequency;
		for(int i=0;E[i];i++)
			frequency[E[i]]++;

		vector<pair<int,char> > frequencyArray;
		frequencyArray.reserve(30);
		for(map<char,int>::iterator i = frequency.begin();i!=frequency.end();i++)
			frequencyArray.push_back(make_pair(i->second,i->first));
		sort(frequencyArray.begin(),frequencyArray.end());
		
		map<char,char> cipher;
		int i=0;
		int j=frequencyArray.size()-1;
		while(i<=j){
			cipher[frequencyArray[i].second]=frequencyArray[j].second;
			cipher[frequencyArray[j].second]=frequencyArray[i].second;
			i++;
			j--;
		}
		for(int i=0;E[i];i++)
			cout<<cipher[E[i]];
		cout<<endl;
	}
}
