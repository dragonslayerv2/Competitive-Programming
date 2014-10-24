#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
	
#define nMAX 1000000
int main(){
	
	srand(time(NULL));
	int n=nMAX;
	for(int i=0;i<n;i++)
		cout<<(char)('a'+rand()%2);
	cout<<endl;
	int t;
	t=nMAX;
	
	char T[][10]={"Select ","Rank "};
	cout<<t<<"\n";
	while(t--){
		int type=rand()%2;
		cout<<T[type];
		if(type){
			int a=1+rand()%n;
			int b=a+(rand()%(n+1-a));
			cout<<a<<" "<<b<<endl;	
		}
		else
			cout<<rand()%10<<" "<<rand()%10<<endl;
	}
}
