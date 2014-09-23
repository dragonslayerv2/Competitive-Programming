#include<iostream>
#include<vector>
#include<map>
#include<cstdlib>
#include<ctime>
using namespace std;


int main(){
	srand(time(NULL));
	int t=1;
	cout<<t<<endl;
	
	while(t--){
		int n=1+rand()%100,k=rand()%100;
		cout<<n<<" "<<k<<endl;
		
		vector<int> a(n);
		for(int i=0;i<n;i++)
			a[i]=i+1;	
		
		for(int i=0;i<n;i++)
			swap(a[rand()%n],a[rand()%n]);
		
		for(int i=0;i<a.size();i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}
