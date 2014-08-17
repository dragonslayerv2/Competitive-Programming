#include<iostream>
#include<cmath>
using namespace std;

int abs(int a){
	return (a>=0?a:-a);
}
int main(){
//	#ifndef ONLINE_JUDGE
//		freopen("test.txt","r",stdin);
//	#endif
	int t;
	cin>>t;
	
	char yes[] = "YES";
	char no[] = "NO";
	
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		bool onWay=false;
		
		if((abs(y)%2)==0)
		{
			if(y==0 && (x>=0&&x<=1))
				onWay=true;
			else if(y>0 &&(x>=-1*y)&&(x<=1+y-2))
				onWay=true;
			else if(y<0 &&(x>=y&&x<=1-y))
				onWay=true;
		}
		if(x==1 &&y>=0&&y<=2)
			onWay=true;
		else if(x>0&&x%2==1){
			if(y>=1-x&&y<=1+x)
				onWay=true;
		}
		else if(x<0&&((-x)%2)==0&&y>=x&&y<=-x)
				onWay=true;


		if(onWay)
			cout<<yes;
		else
			cout<<no;
		cout<<endl;
	}
}
