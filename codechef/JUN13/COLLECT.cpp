#include<iostream>
using namespace std;
//------------------------------------------------------------------------------
#define MOD 3046201
#define MAX 3000020
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


#define C(a,b) ((((fact[a]*ifact[b])%MOD)*ifact[a-b])%MOD)

//------------------------------------------------------------------------------



class BIT
{
	long long tree[100010];
	int n;
	
	public:
		BIT(int A[],int N)
		{
			n=N;
			for(int i=0;i<=n;i++)
				tree[i]=0;
			
			for(int i=1;i<=n;i++)
				increase(i,A[i]);
		}
		long long read(int idx)
		{
			int sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		void increase(int idx, int val)
		{ 
			while (idx <= n)
			{ 
				tree[idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
		long long query(int a,int b)
		{
			return read(b)-read(a-1);
		}
};

//------------------------------------------------------------------------------

#define SIZE 100010
int a[SIZE];

int main()
{
	initfact();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	BIT bit(a,n);
	
	int t;
	cin>>t;
	while(t--)
	{
		char query[100];
		cin>>query;
		
		int A,B;
		cin>>A>>B;
		
		if(query[0]=='c')
		{
			
			bit.increase(A,B-a[A]);	
			a[A]=B;
		}
		else
		{
			long long S=bit.query(A,B);
			long long k=B-A+1;
			long long n;
			
			if(S%k==0)
				n=0;
			else
				n=k-S%k;
			
			long long x=(S+n)/k;
			
			long long ans=C(k,n);
			ans=(ans*fact[S])%MOD;
			
			
			long long inv1=pow(fact[x],k-n);
			inv1=pow(inv1,MOD-2);
			long long inv2=pow(fact[x-1],n);
			inv2=pow(inv2,MOD-2);
			
			ans=(ans*inv1)%MOD;
			ans=(ans*inv2)%MOD;
			
			cout<<ans<<endl;
		}
	}
}
