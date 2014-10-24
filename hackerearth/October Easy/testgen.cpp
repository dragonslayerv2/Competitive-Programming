#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

void printSegment(int high){
	int l=rand()%high;
	int r=l-1;
	while(l>r){
		r=rand()%(high+1);
	}
	cout<<l<<" "<<r<<endl;
}
int main(){
	srand(time(NULL));
	int n=1+rand()%10000;
	cout<<n<<" ";
	printSegment(20);
	while(n--)
	{
		int l=1+rand()%10;
		int r=1+rand()%10;
		while(l-r<0){
			r=1+rand()%(10+1);
		}
		cout<<l<<" "<<r<<endl;
	}
}
