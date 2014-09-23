#include<iostream>
#include<cmath>
using namespace std;

int main(){
	freopen("test2.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		double p;
		double time;
		cin>>p>>time;
		//printf("%.4lf\n",pow(1+p,time/1440.0)exit'-1);
		printf("%.4lf\n",1-pow(1-p,time/1440.0));
	}
}
