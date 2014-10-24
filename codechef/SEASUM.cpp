#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1000000000+7;

template<class T> class matrix
{	
	public:
		typedef T value_type;
	private:
		vector<vector<T> > M;
	public:
		matrix(){}
		
		matrix(int rSize,int cSize)
		{
			M.assign(rSize,vector<value_type>(cSize));	
		}

		void assign(int rSize,int cSize)
		{
			M.assign(rSize,vector<value_type>(cSize));	
		}
		
		vector<value_type>& operator[](int i)
		{
			return M[i];
		}
		
		
		int rowSize() const
		{
			return M.size();
		}
		int columnSize() const
		{
			if(M.size()==0)
				return 0;
			else
				return M[0].size();
		}
		matrix<value_type> operator *(matrix<value_type> B) //assumes matricces are multiplicable
		{
			matrix<value_type> &A=*this;
			matrix<value_type> temp(A.rowSize(),B.columnSize());
			
			for(int i=0;i<temp.rowSize();i++){
			
				for(int j=0;j<temp.columnSize();j++){
					long long ans=0;
					for(int k=0;k<B.rowSize();k++){
						ans=(ans+A[i][k]*B[k][j])%MOD;
						ans%=MOD;
					}
					temp[i][j]=ans;
				}
			}
			return temp;
		}
		
		matrix<value_type> operator %(value_type MOD)
		{
			matrix<value_type> temp(rowSize(),columnSize());
			for(int i=0;i<rowSize();i++)
				for(int j=0;j<columnSize();j++)
					temp[i][j]=M[i][j]%MOD;
			return temp;
		}
		void clear()
		{
			M.clear();
		}
		
		static matrix<value_type> identity(int i)
		{
			matrix<value_type> X;
			X.assign(i,i);
			for(int j=0;j<i;j++)
				X[j][j]=1;	
			return X;
		}
};

template<class T> T p(T n,long long m,int MOD)
{
    if(m==0) 
		return matrix<long long>::identity(n.rowSize());
    
    T x=p(n,m/2,MOD);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
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

inline long long readlong() 
{
	int flag=1;
    long long n = 0;
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


int main(){
	int t;
	t=readLong();
	
	matrix<long long> T(2,2);
	matrix<long long> base(2,1);
	base[0][0]=1;
	base[1][0]=3;
	
	T[0][0]=0;
	T[0][1]=1;
	T[1][0]=2;
	T[1][1]=2;
	while(t--){
		int n;
		n=readLong();
		if(n==1)
			cout<<1;
		else if(n==2)
			cout<<3;
		else
			cout<<((p(T,n-2,MOD)*base)%MOD)[1][0];
		cout<<endl;
	}
}
