#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int index,n;
		cin>>index>>n;
		int pos ;
		switch(index){
			case 1:
				if(n==0)
					pos=1;
				else if(n%2==0)
					pos=1;
				else
					pos=0;
				break;
		 	case 0:
			case 2:
				if(n==0)
					pos=index;
				else if(n%2==0)
					pos = 0;
				else
					pos = 1;
				break;
		}
		cout<<pos<<endl;
	}
}
