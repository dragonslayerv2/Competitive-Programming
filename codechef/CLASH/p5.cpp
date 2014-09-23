#include<iostream>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("p5.txt","r",stdin);
	#endif
	
	int t;
	cin>>t;
	while(t--){
		int initial;
		cin>>initial;
		int a[2][2];
		cin	>>a[0][0]>>a[0][1]
			>>a[1][0]>>a[1][1];
			
		int x,y;
		cin>>x>>y;
		
		int maxCoordinate = max(x,y);
		
		int MSB=-1;
		int setCount=0;
		while(maxCoordinate){
			MSB++;
			setCount+=(maxCoordinate&1);
			maxCoordinate>>=1;
		}
		
		long long matrixSize = (1<<(MSB+(setCount>1)));

		unsigned long long ans = 1;
		while(matrixSize>1){
		
			bool isDown = (x>(matrixSize/2));
			bool isRight = (y>(matrixSize/2));
			
			if(isDown)
				x-=(matrixSize/2);
			if(isRight)
				y-=(matrixSize/2);
			ans*=a[isDown][isRight];
			
			matrixSize/=2;
		}
		cout<<ans<<endl;
	}
}
