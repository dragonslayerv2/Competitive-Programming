#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

struct cmp{
	bool operator ()(pair<char *,int> a,pair<char*,int> b){
		return strcmp(a.first,b.first)<0;
	}
};
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	char firstNames[n][55],secondNames[n][55];
	vector<pair<char *,int> > values;
	values.reserve(2*n);
	for(int i=0;i<n;i++){
		cin>>firstNames[i]>>secondNames[i];
		values.push_back(make_pair(firstNames[i],i+1));
		values.push_back(make_pair(secondNames[i],i+1));
	}
	sort(values.begin(),values.end(),cmp());
	int currentAt=0;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		while(currentAt<values.size()&&values[currentAt].second!=a){
			currentAt++;
		}
		if(currentAt==values.size())
			break;
	}
	if(currentAt==values.size())
		cout<<"NO";
	else
		cout<<"YES";
}


