#include<iostream>
#include<cstdio>
using namespace std;

int main(){int arr[2][3]={2,1,4,3,6,5};
	int i,j;
	for(i = 0 ;i<3;i++){
		for(j=1;j<++i+2;j++){
			printf("%d",arr[1][0]);
			break;
		}	
		for(i=j;i<4;i++)
			cout<<arr[1][2];
	}
}
