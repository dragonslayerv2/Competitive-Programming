#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define MAX 1000000
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));

#define square(i) (i*i)
#define cube(i) (i*i*i)
map<int,int> prime3;
vector<int> prime1;
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
    for(int i=0;i<=MAX;i++)
    {
		if(isSet(i))
		{
			prime1.push_back(i);
		}
	}
                    
}

int main()
{
	sieve();
	while(1)
	{
		int n;
		cin>>n;
		if(n==0)
			break;
		int p1=0,p2=0,p3=0;
		for(int i=0;i<prime1.size()&&cube(prime1[i])<=n;i++)
		{
			bool found=false;
			for(int j=0;j<prime1.size()&&square(prime1[j])<=n-cube(prime1[i]);j++)
			{
				if(isSet((n-cube(prime1[i])-square(prime1[j]))))
				{
					p1=n-cube(prime1[i])-square(prime1[j]);
					p2=prime1[j];
					p3=prime1[i];
					found=true;
				}
			}
			if(found)	break;
		}
		cout<<p1<<" "<<p2<<" "<<p3<<endl;
	}
}
