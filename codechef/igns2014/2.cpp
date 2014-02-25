#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;

string hashstring(string a,char HASHCHAR='#')
{
	//---------------------- generating hashed string---------------------------
	string hashedstring(a+a+' ');
	int k=0;
	hashedstring[k]=HASHCHAR;
	k++;
	for(int i=0;i<a.size();i++)
	{
		hashedstring[k++]=a[i];
		hashedstring[k++]=HASHCHAR;
	}
	//--------------------------------------------------------------------------
	return hashedstring;
}

vector<int> LPS(const string &a,char HASHCHAR='#')
{
	//---------------------- generating hashed string---------------------------
	vector<char> hashedstring(2*a.size()+1);
	int k=0;
	hashedstring[k]=HASHCHAR;
	k++;
	for(int i=0;i<a.size();i++)
	{
		hashedstring[k++]=a[i];
		hashedstring[k++]=HASHCHAR;
	}
	//--------------------------------------------------------------------------
	vector<int> P(hashedstring.size(),0);
	
	int C=0;
	int R=0;
	for(int i=1;i<hashedstring.size()-1;i++)
	{
		int i_mirror=C*2-i;
		P[i] = (R > i) ? min (R-i, P[i_mirror]):0;

		 while (hashedstring[i+1+P[i]]==hashedstring[i-1-P[i]])      
		 	P[i]++;
		
		if (i + P[i] > R) 
		{
			C = i;      
			R = i+P[i];    
		}
	}
	return P;
}


#define MAX 10010000
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));

int prime_count[MAX];
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
    for(int i=1;i<MAX;i++)
    {
    	if(isSet(i))
    		prime_count[i]=prime_count[i-1]+1;
    	else
    		prime_count[i]=prime_count[i-1];
    }
}

char S[10000000];
int main()
{
	sieve();
	int t;
	scanf("%d\n",&t);
	while(t--)
	{
		cin.getline(S,sizeof(S));
		string a=S;
		vector<int> pallindrome_count=LPS(a);
		int count=0;
		for(int i=1;i<pallindrome_count.size()-1;i++)
		{
			if(pallindrome_count[i]==0||pallindrome_count[i]==1)
				continue;
			else if(pallindrome_count[i]%2==0)
				count++;
			else
				count+=prime_count[pallindrome_count[i]]-1;
		}
		printf("%d\n",count);
	}
}
