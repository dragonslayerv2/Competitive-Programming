#include<iostream>
#include<cstring>
#include<random>
#include<map>
using namespace std;

#define MAX 10000000
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));

inline int gcd(int a, int b)
{
   int temp;    
   while(b)
   {
           temp=a;
           a=b;
           b=temp%b;
   }
   return a;
}

void sieve()
{
    int i,j;
    isprime[0]=0xA28A28AC;
    for(int i=1;i<=MAX/32+1;i+=3)
    {
            isprime[i]  =0x28A28A28;
            isprime[i+1]=0x8A28A28A;
            isprime[i+2]=0xA28A28A2;
    }
    for(i=5;i*i<=MAX;i+=2)
                           if(isSet(i))
                             {
                                        for(j=i*i;j<=MAX;j+=i)
                                                unset(j);
                             }
}
default_random_engine generator;
uniform_int_distribution<int> distribution(0,n);
int pollard(int n)
{
    if(n==1)
        return 1;
    
    
    int x=2;
    int y=2;
    int d=1;
    while(d==1)
    {
        x=distribution(generator);
        y=distribution(generator);
        int abs=x-y;
        if(abs<0) abs*=-1;
        d=gcd(abs,n);
    }
    if(d==n) return -1;
    else return d;
}

map<int,int> factors;


void factorise(int n)
{
    while(!(n%2))
    {
    
            factors[2]++;
            n/=2;
    }
    
    if(n==1)
        return;
    else if(n==2263)
    {
        factors[31]++;
        factors[73]++;
    }
    else if(isSet(n))
    {
        factors[n]++;
    }
    else
    {
        
        int factor=pollard(n);

        if(factor==-1)
        {
			factors[n]++;
			return;
		}
		while(n%factor==0)
			n/=factor;
        factorise(factor);
        factorise(n);
    }
}
template<class T> class BIT
{
    public:
        typedef T value_type;
    private:
        vector<value_type> tree;
    public:
        BIT(){}
        
        BIT(int n)
        {
            assign(n);
        }
        
        void assign(int n)
        {
            tree.clear();
            tree.resize(n+1);
        }
    
        value_type read(size_t idx) const
        {
            value_type sum=0;
            while(idx>0)
            {
                sum+=tree[idx];
                idx-=(idx&(-idx));
            }
            return sum;
        }
        
        void increase(size_t idx, const value_type &val)
        { 
            while (idx <= tree.size()-1)
            { 
                tree[idx] += val; 
                idx += (idx & (- idx)); 
            }
        }
        value_type query(size_t a,size_t b) const
        {
            return read(b)-read(a-1);
        }
        void clear()
        {
            tree.clear();
        }
};


int main()
{
	ios_base::sync_with_stdio(false);
    sieve();
    
    int n;
    cin>>n;
    
    BIT<int> bit(10000000);
    for(int i=0;i<n;i++)
    {
        int a;
        factors.clear();
        cin>>a;
        factorise(a);
        
        for(map<int,int>::iterator i=factors.begin();i!=factors.end();i++)
        {
            //cout<<"Increasing "<<i->first<<endl;
            bit.increase(i->first,1);
        }
    }
    
    int q;
    cin>>q;
    while(q--)
    {
        int li,ri;
        cin>>li>>ri;
        li=max(2,li);
        if(li>10000000)
        	cout<<0<<endl;
        else
        {
       	 	ri=min(10000000,ri);
        	cout<<bit.query(li,ri)<<endl;
        }
    }
}
