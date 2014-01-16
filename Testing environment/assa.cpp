#include<iostream>
#include<cstdlib>
using namespace std;

long long modulo(long long a,long long b,long long c){
    long long x=1,y=a; // long long is taken to avoid overflow of long longermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

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

bool isPrime(long long p,long long iteration=10){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(long long i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}


inline long long resolve(long long a)
{
	if(a%4==1)
		return a;
	else
	{
		a=a/4;
		a=(a+1)*4+1;
	}
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		long long count=0;
		
		if(2>=a&&2<=b) // 2 is an exception
			count++;
			
		for(long long i=resolve(a);i<=b;i+=4)
			if(isPrime(i))
		{		count++;
		//	cout<<i<<" ";
		}
		cout<<count<<endl;
	}

}
