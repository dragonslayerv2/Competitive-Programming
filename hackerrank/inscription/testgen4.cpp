#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int n;
	n=rand()%10+3;
	cout<<n<<endl;
	int a=rand()%10,b=rand()%10,c=rand()%10,d=rand()%10;
	cout<<1+a<<" "<<1+b<<" "<<1+c<<" "<<1+d<<endl;
	
	cout<<rand()%10<<" "<<rand()%10<<endl;
	
}
