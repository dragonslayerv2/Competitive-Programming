#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int n=1+rand()%1000;
	cout<<n<<endl;
	for(int i=0;i<n;i++)
		cout<<rand()%10<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		int l=1+rand()%n;
		int r=l+rand()%(n-l+1);
		cout<<l<<" "<<r<<endl;
	}
	int q=1000;
	cout<<q<<endl;
	while(q--){
		int type=rand()%2+1;
		cout<<type<<" ";
		if(type==1)
			cout<<1+rand()%n<<" "<<rand()%100<<endl;
		else{
			int l=1+rand()%n;
			int r=l+rand()%(n-l+1);
			cout<<l<<" "<<r<<endl;
		}
	}
}
