#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	char a;
	int lastCount=0;
	char lastCharacter='a';
	int maxCount=0;
	char  maxCharacter='a';
	while(cin>>a){
		if(a==lastCharacter){
			lastCount++;
		}
		else{
			lastCharacter=a;
			lastCount=1;
		}
		
		if(maxCount<lastCount)
		{
			maxCount=lastCount;
			maxCharacter=lastCharacter;
		}
		else if(maxCount==lastCount){
			maxCharacter=min(maxCharacter,lastCharacter);
		}
	}
	cout<<maxCharacter<<endl;
	cout<<maxCount<<endl;
}
