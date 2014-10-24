#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int n=5,m=4;
	cout<<n<<" "<<m<<endl;
	for(int i=0;i<n;i++)
		cout<<rand()%10<<" ";
	cout<<endl;
	while(m--){
		int a=rand()%n;
		int b=-1;
		while(b<a){
			b=rand()%n;
		}
		cout<<a+1<<" "<<b+1<<endl;
	}
	
}
