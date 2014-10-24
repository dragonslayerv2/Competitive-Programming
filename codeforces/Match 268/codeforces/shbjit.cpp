#include<iostream>
#include<stack>
using namespace std;


void toBinary(char a){
	stack<int> S;
	for(int i=0;i<8;i++){
		S.push(a&1);
		a>>=1;
	}
	while(!S.empty()){
		cout<<S.top();
		S.pop();
	}
}
int main(){
	int a=300;
	
	char *b = (char*)&a;
	toBinary(*b);
	b++;
	toBinary(*b);
	b++;
	toBinary(*b);
	b++;
	toBinary(*b);
}
/*
0000 0000
0000 0000
0000 0001
0010 1100
*/
