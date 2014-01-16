
#include<stdio.h>
#include<stdlib.h>
using namespace std;
long long mulmod(long long a,long long b,long long c){
long long x = 0,y=a%c;
    while(b > 0){
    		if(b%2 == 1){
    		x = (x+y)%c;
    		}
    		y = (y*2)%c;
    		b /= 2;
    		}
    	return x%c;
   	 }


    long long modulo(long long a,long long b,long long c){
    long long x=1,y=a;
    while(b > 0){
    	if(b%2 == 1){
   	 	x = mulmod(x,y,c);
    	}
    	y =mulmod(y,y,c);
    	b /= 2;
    	}
    return x%c;
    }


bool Fermat(long long n){
    if(n<2){
        return false;
    }
    if(n!=2 && n%2==0){
        return false;
    }
    long long s=n-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<2;i++){
        long long a=rand()%(n-1)+1,temp=s;
        long long mod=modulo(a,temp,n);
        while(temp!=n-1 && mod!=1 && mod!=n-1){
            mod=mulmod(mod,mod,n);
            temp *= 2;
        }
        if(mod!=n-1 && temp%2==0){
            return false;
        }
    }
    return true;
}
main(){
int t;
scanf("%d",&t);
while(t--){
long long n;
scanf("%lld",&n);
while(n>0){
if(!(n%2||n%3||n%5)){}
else
{
if(Fermat(n)){
printf("%lld\n",n);

break;
}
if(n%2)
n-=2;
else
n--;
}
if(n==2||n==3||n==5) {
printf("%lld\n",n);
break;}
}
}
return 0;
} 
