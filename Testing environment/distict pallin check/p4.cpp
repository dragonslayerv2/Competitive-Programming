/*
	Name: Longest Pallindromic Substring(Manchers Algorithm)
	Copyright: 
	Author: Shobhit Saxena
	Date: 10/12/13 20:18
	Description: This is a O(n) algorithm to solve Longest Pallindromic Substring Problem.
				Space O(n).
				refer to  http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
*/

#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;

#define HASH_CHAR '#'
#define MAX 100100
//-------------------- suffix array dc3 algorithm-------------------------------

unsigned char mask[] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };
#define tget(i) ( (t[(i)/8]&mask[(i)%8]) ? 1 : 0 )
#define tset(i, b) t[(i)/8]=(b) ? (mask[(i)%8]|t[(i)/8]) : ((~mask[(i)%8])&t[(i)/8])
#define chr(i) (cs==sizeof(int)?((int*)s)[i]:((unsigned char *)s)[i])
#define isLMS(i) (i>0 && tget(i) && !tget(i-1))


void getBuckets(unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
    int i, sum = 0;
    for (i = 0; i <= K; i++)
        bkt[i] = 0; 
    for (i = 0; i < n; i++)
        bkt[chr(i)]++; 
    for (i = 0; i <= K; i++) {
        sum += bkt[i];
        bkt[i] = end ? sum : sum - bkt[i];
    }
}

void induceSAl(unsigned char *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
    int i, j;
    getBuckets(s, bkt, n, K, cs, end); 
    for (i = 0; i < n; i++) {
        j = SA[i] - 1;
        if (j >= 0 && !tget(j))
            SA[bkt[chr(j)]++] = j;
    }
}

void induceSAs(unsigned char *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
    int i, j;
    getBuckets(s, bkt, n, K, cs, end); 
    for (i = n - 1; i >= 0; i--) {
        j = SA[i] - 1;
        if (j >= 0 && tget(j))
            SA[--bkt[chr(j)]] = j;
    }
}

void SA_IS(unsigned char *s, int *SA, int n, int K, int cs) {
    int i, j;
    unsigned char *t = (unsigned char *) malloc(n / 8 + 1); // LS-type array in bits

    tset(n-2, 0);
    tset(n-1, 1); 
    for (i = n - 3; i >= 0; i--)
        tset(i, (chr(i)<chr(i+1) || (chr(i)==chr(i+1) && tget(i+1)==1))?1:0);
    
    int *bkt = (int *) malloc(sizeof(int) * (K + 1)); 
    getBuckets(s, bkt, n, K, cs, true); 
    for (i = 0; i < n; i++)
        SA[i] = -1;
    for (i = 1; i < n; i++)
        if (isLMS(i))
            SA[--bkt[chr(i)]] = i;
    induceSAl(t, SA, s, bkt, n, K, cs, false);
    induceSAs(t, SA, s, bkt, n, K, cs, true);
    free(bkt);
    
    int n1 = 0;
    for (i = 0; i < n; i++)
        if (isLMS(SA[i]))
            SA[n1++] = SA[i];
    
    for (i = n1; i < n; i++)
        SA[i] = -1; 
    int name = 0, prev = -1;
    for (i = 0; i < n1; i++) {
        int pos = SA[i];
        bool diff = false;
        for (int d = 0; d < n; d++)
            if (prev == -1 || chr(pos+d) != chr(prev+d) || tget(pos+d) != tget(prev+d)) {
                diff = true;
                break;
            } else if (d > 0 && (isLMS(pos+d) || isLMS(prev+d)))
                break;
        if (diff) {
            name++;
            prev = pos;
        }
        pos = (pos % 2 == 0) ? pos / 2 : (pos - 1) / 2;
        SA[n1 + pos] = name - 1;
    }
    for (i = n - 1, j = n - 1; i >= n1; i--)
        if (SA[i] >= 0)
            SA[j--] = SA[i];
    
    int *SA1 = SA, *s1 = SA + n - n1;
    if (name < n1)
        SA_IS((unsigned char*) s1, SA1, n1, name - 1, sizeof(int));
    else
    
        for (i = 0; i < n1; i++)
            SA1[s1[i]] = i;
    
    bkt = (int *) malloc(sizeof(int) * (K + 1)); 
    
    getBuckets(s, bkt, n, K, cs, true); 
    for (i = 1, j = 0; i < n; i++)
        if (isLMS(i))
            s1[j++] = i; 
    for (i = 0; i < n1; i++)
        SA1[i] = s1[SA1[i]]; 
    for (i = n1; i < n; i++)
        SA[i] = -1; 
    for (i = n1 - 1; i >= 0; i--) {
        j = SA[i];
        SA[i] = -1;
        SA[--bkt[chr(j)]] = j;
    }
    induceSAl(t, SA, s, bkt, n, K, cs, false);
    induceSAs(t, SA, s, bkt, n, K, cs, true);
    free(bkt);
    free(t);
}

const int maxn = 2*MAX+1;
int sa[maxn];
int lcp[maxn];
int rank[maxn];
unsigned char *s;
int n;

void calc_lcp() {
    for (int i = 0; i < n; i++)
        rank[sa[i]] = i;
    for (int i = 0, h = 0; i < n; i++) {
        if (rank[i] < n ) {
            for (int j = sa[rank[i] + 1]; s[i + h] == s[j + h]; ++h)
                ;
            lcp[rank[i]] = h;
            if (h > 0)
                --h;
        }
    }
}
//-------------------------------------------------------------------------------
unsigned char mystring[2*MAX+1];
int P[2*MAX+1];

int LPS(const unsigned char *hashedstring)
{	
	P[0]=0;
	int C=0;
	int R=0;

	for(int i=1;hashedstring[i];i++)
	{
		int i_mirror=C*2-i;
		P[i] = (R > i) ? min (R-i, P[i_mirror]):0;
		
		 while ((i-1-P[i])>=0&&(hashedstring[i+1+P[i]])&&hashedstring[i+1+P[i]]==hashedstring[i-1-P[i]])   
		 {   	
		 	P[i]++;
		 }
		
		if (i + P[i] > R) 
		{
			C = i;      
			R = i+P[i];    
		}
	}
}


int main()
{	
	mystring[0]=HASH_CHAR;
	int i=1;
	char ch;
	
	while(isalpha((ch=cin.get())))
	{
		mystring[i++]=ch;
		mystring[i++]='#';
	}
	mystring[i]='\0';
	//------------- suffix array part-------------------------------------------
		n = i;
    	s = mystring;
    	SA_IS(s, sa, n + 1, 256, 1);
    	calc_lcp();
    	lcp[n]=0;
	//--------------------------------------------------------------------------
	LPS(mystring);
	
	vector<pair<int,pair<int,char> > > finals;
	for(int i=0;i<n;i++)
	{
		if(P[sa[i+1]])
			finals.push_back(make_pair(P[sa[i+1]],make_pair(lcp[i+1],mystring[sa[i+1]])));
		else if(finals.size())
			finals.back().second.first=min(finals.back().second.first,lcp[i+1]);
	}

	long long distinct=ceil(((double)finals[0].first)/2);
	
	for(int i=1;i<finals.size();i++)
	{
		int common=min(finals[i-1].first,finals[i].first); // size of pallindromes
		common=min(common,finals[i-1].second.first-1);
		if(common<=0)
			common=0;
		
		distinct+=ceil(((double)finals[i].first)/2);
		distinct-=ceil(((double)common)/2);
	}
	cout<<distinct<<endl;
}
