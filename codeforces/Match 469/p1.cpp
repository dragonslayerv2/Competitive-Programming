#include<iostream>
using namespace std;


void print(int a,char op, int b, int output){
	cout<<a<<" "<<op<<" "<<b<<" = "<<output<<endl;
}
int main(){
	int n;
	cin>>n;
	if(n==1||n==2||n==3)
		cout<<"NO";
	else{
		cout<<"YES"<<endl;
		if(n==4){
		print(1,'*',2,2);
		print(2,'*',3,6);
		print(6,'*',4,24);
	}
	else if(n==5){
		print(1,'+',5,6);
		print(6,'*',4,24);
		print(3,'-',2,1);
		print(1,'*',24,24);
	}
	else if(n==6){
		print(6,'-',5,1);
		print(1,'*',1,1);
		print(2,'*',1,2);
		print(3,'*',2,6);
		print(6,'*',4,24);
	}
	else if(n==7){
		print(5,'-',1,4);
		print(4,'-',2,2);
		print(7,'-',6,1);
		print(1,'*',2,2);
		print(2,'*',3,6);
		print(6,'*',4,24);
	}	
	else if(n==8){
		print(8,'-',4,4);
		print(5,'-',1,4);
		print(4,'-',2,2);
		print(7,'-',6,1);
		print(1,'*',2,2);
		print(2,'*',3,6);
		print(6,'*',4,24);
	}
	else if(n==9){
		print(2,'-',1,1);
		print(5,'-',4,1);
		print(7,'-',6,1);
		print(9,'-',1,8);
		print(8,'-',1,7);
		print(7,'-',1,6);
		print(6,'-',3,3);
		print(3,'*',8,24);
	}
	else if(n>9){
		cout<<"1 + "<<n<<" = "<<n+1<<endl;
		cout<<"2 + "<<n-1<<" = "<<n+1<<endl;
		cout<<n+1<<" - "<<n+1<<" = "<<0<<endl;
		for(int i=1;i<=n;i++){
			if(i==1||i==2||i==3||i==8||i==n||i==n-1)
				continue;
			else
				cout<<i<<" * "<<0<<" = "<<0<<endl;
		}
		cout<<3<<" * "<<8<<" = "<<24<<endl;
		cout<<24<<" + "<<0<<" = "<<24<<endl;
	}
	}
	
}
