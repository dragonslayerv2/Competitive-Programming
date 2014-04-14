#include<iostream>
#include<vector>
using namespace std;

#define MAX 10000
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));


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
            for(j=i*i;j<=MAX;j+=i)
                unset(j);
}


int main()
{
	sieve();
	vector<bool> squareNumbers(MAX);
	for(int i=1;i*i<MAX;i++)
		for(int j=i;j<MAX;j++)
		{
			if(i*i+j*j<=MAX)
				squareNumbers[i*i+j*j]=true;
			else
				break;
		}
	
	vector<int> S;
	S.push_back(0);
	S.reserve(MAX);
	for(int i=2;i<MAX;i++)
		if(isSet(i)&&squareNumbers[i])
			S.push_back(i);
	
	vector<vector<int> > A(5,vector<int>(MAX));
	
	A[1][0]=A[2][0]=A[3][0]=A[4][0]=1;
	
	for(int i=1;i<MAX;i++)
	{
		A[1][i]=A[1][i-1];
		
		A[2][i]=A[1][i];
		if(i>=2)
			A[2][i]+=A[2][i-2];
		
		A[3][i]=A[2][i];
		if(i>=3)
			A[3][i]+=A[3][i-3];
		
		A[4][i]=A[3][i];
		if(i>=4)
			A[4][i]+=A[4][i-4];
	}
	
	
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
	//	cout<<S[n]<<endl;
		cout<<A[k][S[n]]<<endl;
	}
}
