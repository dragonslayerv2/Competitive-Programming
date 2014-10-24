#include<iostream>
using namespace std;

int func(int i=0){
	cout<<i<<endl;
	func(i+1);
}
int main(){
	func();
}
