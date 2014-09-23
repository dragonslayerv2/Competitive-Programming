#include<stdio.h>

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%s\n",(n&(-n))==n?"YES":"NO");
	}
}
