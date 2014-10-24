#include<iostream>
using namespace std;

int main(){
	long long a;
	cin>>a;
	a*=2;
	long long count=0;
	for(long long f=1;f<=2000000;f++){
		if(a-f-3*f*f>=0&&(a-f-3*f*f)%6==0){
			count++;
		}
	}
	cout<<count;
}
