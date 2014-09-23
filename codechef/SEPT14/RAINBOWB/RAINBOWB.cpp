#include<iostream>
using namespace std;

#define MOD 1000000007
#define MAX 1000010
long long fact[MAX];
long long ifact[MAX];

long long pow(long long n,int m)
{
    if(m==0) return 1;
    long long x=pow(n,m/2);
    if(m%2==0) 
    	return (x*x)%MOD;
    else
    	return (((x*x)%MOD)*n)%MOD;
}

void initfact(int n=MAX-1)
{
     int i;
     fact[0]=1;
     for(i=1;i<=n;i++)
        fact[i] = i*fact[i-1]%MOD;
     ifact[n] = pow(fact[n],MOD-2);
     for(i=n;i>0;i--)
     ifact[i-1] = ifact[i]*i%MOD;
}

#define C(a,b) ((((fact[a]*ifact[b])%MOD)*ifact[(a)-(b)])%MOD)

int main(){
	initfact();
	int n;
	cin>>n;
	if((n&1)==0)
		n-=2;
	n/=2;
	n-=6;
//	cout<<n<<endl;
	long long combinations = 0;
	for(int i=0;i<=n;i++){
		//cout<<"Adding C "<<i+5<<" "<<5<<" ";
		//cout<<C(i+5,5)<<endl;
		combinations+=C(i+5,5);
		combinations%=MOD;
	}
		
	cout<<combinations;
}

