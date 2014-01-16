#include <cstdio>
#include <cassert>
#include <cstring>
using namespace std;

typedef long long ll;
#define MOD 1000000007

/*
Instead of calculating the entire result in an array, I chose to optimize calculations by
precomputing the number of times a prime occurs, and calculate the interim results.

Since we are doing 500,000 out of 5,000,000 calculations, this should be faster.
*/

/*Using bits instead of bytes makes sieving faster.*/
int A[1<<18];
#define isSet(n) A[n>>5]&(1<<(n&31))
#define unsetAt(n) A[n>>5] &= ~(1<<(n&31))

/*calculates a^b modulo MOD.*/
int mpow(int n, int r) {
    if(!r) return 1;
    ll res=mpow(n,r>>1);
    res=((ll)res*res)%MOD;
    if(r&1) res=((ll)res*n)%MOD;
    return res;
}

/*
P stores the prime, Pc stores the number of times the prime occurs before the next prime.
Thus they look like
2 1
3 2
5 2
7 4
11 2
13 4
17 2
19 4
23 6
and so on..
*/
int P[1<<19], Pc[1<<19], k;
/*Rp[k] stores 1^Pc[0] * 2^Pc[1] * 3^Pc[2] and so on.. till * k^Pc[k] */
int Rp[1<<19];

void pre_calc() {
    memset(A,-1,sizeof(A));
    k=0;
    int p=1, cnt=1;
    for(int i=2;i<=5000011;i++) if(isSet(i)) {
        P[k]=p;
        Pc[k]=cnt;
        k++;
        for(int j=i+i;j<=5000011;j+=i) unsetAt(j);
        p=i;
        cnt=1;
    } else cnt++;
    P[k]=p;
    Pc[k]=cnt;
    k++;
    
    Rp[0]=mpow(P[0], Pc[0]);
    for(int i=1;i<k;i++) Rp[i]=((ll)Rp[i-1]*mpow(i+1, Pc[i]))%MOD;
}

int main() {
    pre_calc();
    int T;
    scanf("%d",&T);
    while(T--) {
        int N;
        scanf("%d",&N);
        
        /*binary search for N and figure out the prime smaller than N*/
        int lo=0, hi=k-1;
        while(lo<hi) {
            int mid=(lo+hi)/2;
            if(mid==lo) mid=mid+1;
            if(P[mid]<=N) lo=mid;
            else hi=mid-1;
        }
        
        /*if N is the last composite number less than the next prime, then we can use Rp*/
        if(P[lo]+Pc[lo]-1==N) printf("%d\n",Rp[lo]);
        else {
            /*Otherwise we can use Rp[lo-1] and calculate the rest.*/
            int res=((ll)Rp[lo-1]*mpow(lo+1, N-P[lo]+1))%MOD;
            printf("%d\n",res);
        }
    }
    return 0;
}
