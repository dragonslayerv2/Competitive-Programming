#include<vector>
using namespace std;

const int MOD = 1000000000+7;

template<class T> class matrix
{	
	public:
		typedef T value_type;
	private:
		value_type M[2][2];
	public:
		matrix(){}
		
		value_type* operator[](int i)
		{
			return M[i];
		}
};
matrix<unsigned int> temp;

#include<iostream>
using namespace std;

matrix<unsigned int>& operator *(matrix<unsigned int> &A,matrix<unsigned int> &B)
{
	int p=(((long long)A[0][0]*B[0][0])+((long long)A[0][1]*B[1][0]))%MOD;
	int q=(((long long)A[0][0]*B[0][1])+((long long)A[0][1]*B[1][1]))%MOD;
	int r=(((long long)A[1][0]*B[0][0])+((long long)A[1][1]*B[1][0]))%MOD;
	int s=(((long long)A[1][0]*B[0][1])+((long long)A[1][1]*B[1][1]))%MOD;
	
	temp[0][0]=p;
	temp[0][1]=q;
	temp[1][0]=r;
	temp[1][1]=s;
	return temp;
}

template<class T> T& p(T& n,int m)
{
    if(m==1) 
		return n;
    matrix<unsigned int> &x=p(n,m/2);
    if(m&1) 
    	return (x*x)*n;
    else
    	return (x*x);
}

#include<stdio.h>
#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif

inline int readInt() 
{
	int flag=1;
    int n = 0;
    char c;
    int sign=1;
    while (1)
    { 		
		c=GETCHAR();
    	if(c=='-')	sign=-1;
        else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
        else if(flag!=1) break; 
   }
    return sign*n;
}

inline void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     // buf[10] = 0;
     buf[10] = '\n';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}

int main(){
	int t;
	t=readInt();
	
	matrix<unsigned int> T;
	matrix<unsigned int> base;
	base[0][0]=1;
	base[1][0]=3;
	base[0][1]=0;
	base[1][1]=0;
	
	T[0][0]=0;
	T[0][1]=1;
	T[1][0]=2;
	T[1][1]=2;
	while(t--){
		int n;
		n=readInt();
		if(n==1)
			writeInt(1);
		else if(n==2)
			writeInt(3);
		else{
			writeInt((p(T,n-2)*base)[1][0]);
		}
	}
}
