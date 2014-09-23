#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
#define MAX 10000

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
     	fact[i] = (i*fact[i-1])%MOD;
     ifact[n] = pow(fact[n],MOD-2);
     for(i=n;i>0;i--)
     ifact[i-1] = (ifact[i]*i)%MOD;
}

#define C(a,b) ((((fact[a]*ifact[b])%MOD)*ifact[(a)-(b)])%MOD)

vector<vector<long long> > DP;
long long generate(int k,int s){
	if(k==0&&s==0){
		return 1;
	}
	else if(s<=0||k<=0)
		return 0;
	else if(DP[k][s]==-1)
	{
		long long ans=0;
		for(int i=1;i<=s;i++){
			ans+=C(s,i)*generate(k-1,s-i);
			ans%=MOD;
		}
		DP[k][s]=ans;
	}
	return DP[k][s];
}

int main(){
	initfact();
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		int k,s;
		cin>>k>>s;
		
		cout<<"Case #"<<t<<": ";
		DP.assign(k+1,vector<long long>(s+1,-1));
		cout<<generate(k,s);
		cout<<endl;
	}
}
