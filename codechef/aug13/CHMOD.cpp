#include<iostream>
#include<vector>
using namespace std;


long long pow(long long n,long long m,long long MOD)
{
    if(m==0) return 1;
    
    long long x=pow(n,m/2,MOD);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}


#define SCALE 1000000000LL

#define MAXDIGITS 100
class bigint
{
       public:
               long long digit[MAXDIGITS];
               int last_digit;
               int first_digit;
       public: 
               
			   static long long scale;
               bigint(long long a=0)
               {
                        first_digit=last_digit=MAXDIGITS-1;
                        do
                        {
                                 digit[first_digit--]=a%scale;
                                 a/=scale;
                        }while(a);
               }
               bigint operator *(int a);                  
};

bigint bigint::operator *(int a)
{
	bigint res=*this;
	for(int i=res.last_digit;i>res.first_digit;i--)
           {
                   res.digit[i]*=a;
                   if(i!=res.last_digit)
                   {
                                    res.digit[i]+=res.digit[i+1]/scale;
                                    res.digit[i+1]%=scale;                 
                   }
           }
           if(res.digit[res.first_digit+1]/scale!=0)
           {
                                           res.digit[res.first_digit]=res.digit[res.first_digit+1]/scale;
                                           res.digit[res.first_digit+1]%=scale;
                                           res.first_digit--;
           }
           return res;
}




long long bigint::scale=SCALE;


long long operator %(bigint &x,long long MOD)
{
	long long ans=0;
	for(int i=x.first_digit+1;i<=x.last_digit;i++)
	{
		ans=ans*bigint::scale +x.digit[i];
		ans%=MOD;
	}
	return ans;
}


long long inv(bigint &x,long long MOD)
{
	long long X=x%MOD;
	return  pow(X,MOD-2,MOD);
}
int main()
{
	int n;
	cin>>n;
	vector<int> array;
	array.reserve(n);
	array.push_back(1);
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		array.push_back(x);
	}
	
	vector<bigint> multiply;
	multiply.resize(n+1);
	multiply[0]=bigint(1);
	
	for(int i=1;i<=n;i++)
	{
		multiply[i]=multiply[i-1]*array[i];
	}
	throw 1;
	int t;
	cin>>t;
	while(t--)
	{
		int l,r;
		long long MOD;
		cin>>l>>r>>MOD;
		
		cout<<(((multiply[r])%MOD)*inv(multiply[l-1],MOD))%MOD<<endl;
	}
	return 0;
}
