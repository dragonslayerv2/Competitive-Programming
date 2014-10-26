#include<iostream>
#include<cmath>
#include<set>
using namespace std;

int main(){
	set<int> values;
	int prevN;
	cin>>prevN;
	int n;
	while(cin>>n){
		values.insert(abs(n-prevN));
		prevN=n;
	}
	cout<<values.size();
}
