#include<iostream>
#include<stdio.h>
using namespace std;

#define MOD 1000000009LL

void tn(long long a[2][2],long long n)
{      
   
    if(n==1||n==0) return;
    else
    {
        tn(a,n/2);
        long long u,v,w,x;
        u=(a[0][0]*a[0][0]+a[0][1]*a[1][0])%MOD;
        v=(a[0][0]*a[0][1]+a[0][1]*a[1][1])%MOD;
        w=(a[1][0]*a[0][0]+a[1][1]*a[1][0])%MOD;
        x=(a[1][0]*a[0][1]+a[1][1]*a[1][1])%MOD;
        a[0][0]=u;
        a[0][1]=v;
        a[1][0]=w;
        a[1][1]=x;
        if(n%2!=0)
        {
                  u=a[0][1];
                  v=(a[0][0]+a[0][1])%MOD;
                  w=a[1][1];
                  x=(a[1][0]+a[1][1])%MOD;
                  a[0][0]=u;
                  a[0][1]=v;
                  a[1][0]=w;
                  a[1][1]=x;
        }
    }
}

long long fibonicci(long long n)
{
	if(n==0)
		return 1;
	long long T[2][2]={{0,1},{1,1}};
	tn(T,n);
	return T[1][0]%MOD;
}



int main(){
	int t;
	cin>>t;
	while(t--){
		long long a;
		cin>>a;
		cout<<(fibonicci(a)*fibonicci(a+1))%MOD<<endl;
	}
}
